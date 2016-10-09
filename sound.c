/*
 * sound.c
 *
 * Created: 17.02.2016 14:56:51
 *  Author: Sebastian Foerster
 *	Web:	sebastianfoerster86.wordpress.com
 *	License: GPLv2
 */ 

#include "sound.h"
#include "songs.h"
#include <avr/interrupt.h>
#include <avr/pgmspace.h>

// interrupt mode (1 MHz optimized) 
#if USER_NONBLOCKING_MODE
	
	#define DELAY_NOTE_INTERRUPT	40

	volatile uint8_t play_song = 0;

	const uint16_t PROGMEM waits[] = {
		60000 / DELAY_NOTE_INTERRUPT, //dot
		40000 / DELAY_NOTE_INTERRUPT,
		30000 / DELAY_NOTE_INTERRUPT, //dot
		20000 / DELAY_NOTE_INTERRUPT,
		15000 / DELAY_NOTE_INTERRUPT, //dot
		10000 / DELAY_NOTE_INTERRUPT,
		7500 / DELAY_NOTE_INTERRUPT, //dot
		5000 / DELAY_NOTE_INTERRUPT,
		3750 / DELAY_NOTE_INTERRUPT, //dot
		2500 / DELAY_NOTE_INTERRUPT,
		1900 / DELAY_NOTE_INTERRUPT, //dot
		1250 / DELAY_NOTE_INTERRUPT
	};

// speed for non interrupt mode / blocking mode (1 MHz optimized) 
#else
	
	#define DELAY_NOTE			11

	const uint16_t PROGMEM waits[] = {
		60000, //dot
		40000,
		30000, //dot
		20000,
		15000, //dot
		10000,
		7500, //dot
		5000,
		3750, //dot
		2500,
		1900, //dot
		1250
	};

#endif

#if USER_NONBLOCKING_MODE

	void Tone_Int(uint8_t divisor, uint8_t octave);

	ISR(TIMER1_OVF_vect)
	{
		static uint8_t i = 1;			//use to count notes in song (song length max 254 Byte or use 16 bit counter !)
		static uint32_t duration = 0;	//hold tone time
		static uint8_t tone = 0;		//save the state -> play normal note or a break between notes
	
		if(play_song) {
			if(!duration) {
			
				if(i < songlist[play_song-1])
				{
					uint8_t octave = (songlist[play_song] > 0) ? ((songlist[play_song] & 0x07) - 1) : 0;
					//pause between note or next note?
					if(tone) {
						tone = 0;
						duration = 8 * (1 << octave); //between every note make do a little break
					} else {
						tone = pgm_read_byte(((uint8_t*)songlist[play_song-2]) + i-1);
						duration = ((uint32_t)pgm_read_word(&waits[pgm_read_byte(((uint8_t*)songlist[play_song-2]) + i)])) * 32 / tone * (1 << octave);
						
						i+=2;
					}
					
					//play note in dur
					Tone_Int(tone, songlist[play_song]);
	
				}
				else
				{
					//song ends here
					i = 1;
					TIMSK &= ~(1<<TOIE1);
					TCCR1 = 0;
					GTCCR = 0;
					play_song = 0;
				}
			}
			else 
			{
				duration--;
			}
		} 
		else
		{
			TIMSK &= ~(1<<TOIE1);
			TCCR1 = 0;
			GTCCR = 0;
		}
	}

	void Tone_Int(uint8_t divisor, uint8_t octave)
	{
		//set as output, always zero start
		DDRB	|= (1 << GPIO_SPEAKER);
		PORTB	&= ~(1 << GPIO_SPEAKER);
		DDRB	|= (1 << GPIO_SPEAKER_L);
		PORTB	&= ~(1 << GPIO_SPEAKER_L);
	
		//could the sound played?
		if(divisor >= 3) {
			//setup timer
			OCR1C = divisor;
			OCR1A = OCR1C / 2;
		} else {
			//use for a very little pause -> divisor = 0
			OCR1C = 40;
		}
		
		//pause if divisor is 0 or 0xFF -> don't play a tone but we need the overflow interrupt
		if(divisor == 0 || divisor == 0xFF)
		{
			TCCR1 = 0b11000000 | (8- (octave & 0x07));
		}
		else
		{
			TCCR1 = 0b11010000 | (8- (octave & 0x07));
		}
	}

#else


	void delay(uint16_t time)
	{
		for(uint16_t i = 0; i < time; i++)
		{
			for(uint8_t a = 0; a < DELAY_NOTE; a++) {
				asm("nop");
			}
		}
	}

	void Tone(uint8_t divisor, uint8_t octave, uint16_t duration)
	{
	
		//set as output, always zero start
		DDRB	|= (1 << GPIO_SPEAKER);
		PORTB	&= ~(1 << GPIO_SPEAKER);
		DDRB	|= (1 << GPIO_SPEAKER_L);
		PORTB	&= ~(1 << GPIO_SPEAKER_L);
	
		//could the sound played?
		if(divisor >= 3 && divisor != 0xFF) {
			//setup timer
			OCR1C = divisor;
			OCR1A = OCR1C / 2;
			TCCR1 = 0b11010000 | (8- (octave & 0x07));
			GTCCR = USE_COMPARECHANNEL_B;

		}
	
		//wait (blocking function!)
		delay(duration);
	
		// stop the counter
		TCCR1 = 0;
		TCNT1 = 0;
		GTCCR = 0;
	}

#endif

// Play a scale
//song 0 => stop playing
//if a song is already playing this function will do nothing
void playTune(uint8_t song_number)
{
	
	if(song_number > 0) {
		
		//if a song is playing at the moment?
		if(play_song) {
			//don't play another song
			return;
		}
		
		//get the real index
		song_number = GET_DUR_INDEX(song_number);
		
		if(song_number >= sizeof(songlist)) {
			return;
		}
	}
			
	#if USER_NONBLOCKING_MODE

		play_song = song_number;
			
		if(TCCR1 == 0 && play_song) {
			OCR1C = 10;
			TCCR1 = 0b11000000 | 3;
			TIMSK |= (1<<TOIE1);
		}
		
	#else
	
		if(song_number > 0) {
			//(song length max 254 Byte or use 16 bit counter !)
			for(uint8_t i = 1; i < songlist[song_number-1]; i+=2) {
				Tone(pgm_read_byte(((uint8_t *)songlist[song_number-2]) + i-1), songlist[song_number], pgm_read_word(&waits[pgm_read_byte(((uint8_t *)songlist[song_number-2]) + i)]));
			}
		}

	#endif
	

}

//check if a song is already playing
uint8_t is_song_playing(void)
{
	return play_song ? 1 : 0;
}