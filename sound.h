/*
 * sound.h
 *
 * Created: 17.02.2016 15:00:17
 *  Author: Sebastian Foerster
 *	Web:	sebastianfoerster86.wordpress.com
 *	License: GPLv2
 */ 


#ifndef SOUND_H_
#define SOUND_H_

#include <stdio.h>
#include <avr/io.h>

#include "../NespressoBot.h"


//Helper
#define GET_DUR_INDEX(_index)	(_index * 3 - 1)

// should be the function playTune nonblocking (1) or blocking (0)?
#define USER_NONBLOCKING_MODE	1

#define USE_COMPARECHANNEL_B	0b01010000

extern void		playTune(uint8_t song_number);
extern uint8_t	is_song_playing(void);


#endif /* SOUND_H_ */