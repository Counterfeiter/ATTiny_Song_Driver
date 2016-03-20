/*
 * sound.h
 *
 * Created: 17.02.2016 15:00:17
 *  Author: Sebastian Foerster
 *	Web:	sebastianfoerster86@wordpress.com
 */ 


#ifndef SOUND_H_
#define SOUND_H_

#include <stdio.h>
#include <avr/io.h>


//Helper
#define GET_DUR_INDEX(_index)	(_index * 3 - 1)

// should be the function playTune nonblocking (1) or blocking (0)?
#define USER_NONBLOCKING_MODE	1

extern void playTune(uint8_t song_number);


#endif /* SOUND_H_ */