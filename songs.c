/*
 * songs.c
 *
 * Created: 10.03.2016 15:58:08
 *  Author: Sebastian Foerster
 *	Web:	sebastianfoerster86@wordpress.com
 */ 

#include <avr/pgmspace.h>
#include "sound.h"


// Notes
#define C		239
#define CS		225
#define D		213
#define DS		201
#define E		190
#define F		179
#define FS		169
#define G		159
#define GS		150
#define A		142
#define AS		134
#define H		127

#define C2		(239/2)
#define CS2		(225/2)
#define D2		(213/2)
#define DS2		(201/2)
#define E2		(190/2)
#define F2		(179/2)
#define FS2		(169/2)
#define G2		(159/2)
#define GS2		(150/2)
#define A2		(142/2)
#define AS2		(134/2)
#define B2		(127/2)

#define PAUSE	255


#define WAIT_1_D	0
#define WAIT_1		1
#define WAIT_2_D	2
#define WAIT_2		3
#define WAIT_4_D	4
#define WAIT_4		5
#define WAIT_8_D	6
#define WAIT_8		7
#define WAIT_16_D	8
#define WAIT_16		9
#define WAIT_32_D	10
#define WAIT_32		11


//(song length max 254 Byte or use 16 bit counter !)
/////////// SONGS and TONES //////////////
const uint8_t PROGMEM fuer_elise[] = {
	//note  //wait
	//first row
	E2,		WAIT_8,
	DS2,	WAIT_8,
	E2,		WAIT_8,
	DS2,	WAIT_8,
	E2,		WAIT_8,
	H,		WAIT_8,
	D2,		WAIT_8,
	C2,		WAIT_8,
	A,		WAIT_4,
	PAUSE,	WAIT_8,
	C,		WAIT_8,
	E,		WAIT_8,
	A,		WAIT_8,
	H,		WAIT_4,
	PAUSE,	WAIT_8,
	E,		WAIT_8,
	GS,		WAIT_8,
	H,		WAIT_8,
	C2,		WAIT_4,
	PAUSE,	WAIT_4,
	E2,		WAIT_8,
	DS2,	WAIT_8,
	E2,		WAIT_8,
	DS2,	WAIT_8,
	E2,		WAIT_8,
	H,		WAIT_8,
	D2,		WAIT_8,
	C2,		WAIT_8,
	//second row
	A,		WAIT_4,
	PAUSE,	WAIT_8,
	C,		WAIT_8,
	E,		WAIT_8,
	A,		WAIT_8,
	H,		WAIT_4,
	PAUSE,	WAIT_8,
	E,		WAIT_8,
	C2,		WAIT_8,
	H,		WAIT_8,
	A,		WAIT_4_D,
	C2,		WAIT_8,
	D2,		WAIT_8,
	E2,		WAIT_4_D,
	G,		WAIT_8,
	F2,		WAIT_8,
	E2,		WAIT_8,
	D2,		WAIT_4_D,
	F,		WAIT_8,
	E2,		WAIT_8,
	D2,		WAIT_8,
	C2,		WAIT_4_D,
	E,		WAIT_8,
	D2,		WAIT_8,
	C2,		WAIT_8,
	H,		WAIT_2,
	E2,		WAIT_8,
	DS2,	WAIT_8,
	//third row
	E2,		WAIT_8,
	DS2,	WAIT_8,
	E2,		WAIT_8,
	H,		WAIT_8,
	DS2,	WAIT_8,
	C2,		WAIT_8,
	A,		WAIT_4,
	PAUSE,	WAIT_8,
	C,		WAIT_8,
	E,		WAIT_8,
	A,		WAIT_8,
	H,		WAIT_4,
	PAUSE,	WAIT_8,
	E,		WAIT_8,
	GS,		WAIT_8,
	H,		WAIT_8,
	C2,		WAIT_4,
	PAUSE,	WAIT_8,
	E,		WAIT_8,
	E2,		WAIT_8,
	DS2,	WAIT_8,
	//fourd row
	E2,		WAIT_8,
	DS2,	WAIT_8,
	E2,		WAIT_8,
	H,		WAIT_8,
	DS2,	WAIT_8,
	C2,		WAIT_8,
	A,		WAIT_4,
	PAUSE,	WAIT_8,
	C,		WAIT_8,
	E,		WAIT_8,
	A,		WAIT_8,
	H,		WAIT_4,
	PAUSE,	WAIT_8,
	E,		WAIT_8,
	C2,		WAIT_8,
	H,		WAIT_8,
	A,		WAIT_2,
	PAUSE,	WAIT_1,
	PAUSE,	WAIT_1
};

const uint8_t PROGMEM wedding_march[] = {
	//1.
	G2,		WAIT_4,
	G2,		WAIT_8_D,
	G2,		WAIT_16,
	G2,		WAIT_4,
	G2,		WAIT_4,
	G2,		WAIT_2,
	G2,		WAIT_2,
	//2.
	G,		WAIT_4,
	C2,		WAIT_8_D,
	C2,		WAIT_16,
	C2,		WAIT_2,
	G,		WAIT_4,
	D2,		WAIT_8_D,
	H,		WAIT_16,
	C2,		WAIT_2,
	//3.
	G,		WAIT_4,
	C2,		WAIT_8_D,
	F2,		WAIT_16,
	F2,		WAIT_4,
	E2,		WAIT_8_D,
	D2,		WAIT_16,
	C2,		WAIT_8,
	D2,		WAIT_16,
	C2,		WAIT_16,
	H,		WAIT_8_D,
	C2,		WAIT_16,
	D2,		WAIT_2,
	//4.
	G,		WAIT_4,
	C2,		WAIT_8_D,
	C2,		WAIT_16,
	C2,		WAIT_2,
	G,		WAIT_4,
	D2,		WAIT_8_D,
	H,		WAIT_16,
	C2,		WAIT_2,
	//5.
	G,		WAIT_4,
	C2,		WAIT_8_D,
	E2,		WAIT_16,
	G2,		WAIT_4,
	E2,		WAIT_8_D,
	C2,		WAIT_16,
	A,		WAIT_4,
	D2,		WAIT_8_D,
	E2,		WAIT_16,
	C2,		WAIT_2
	
};

const uint8_t PROGMEM chirp[] = {
	A2,		WAIT_8,
	D2,		WAIT_16_D,
	H,		WAIT_32_D,
	D2,		WAIT_16_D
};

const uint8_t PROGMEM chirp2[] = {
	A,		WAIT_16,
	H,		WAIT_32_D,
	D,		WAIT_16_D
};

const uint8_t PROGMEM upscale[] = {
	240,	WAIT_32,
	230,	WAIT_32,
	220,	WAIT_32,
	210,	WAIT_32,
	200,	WAIT_32,
	190,	WAIT_32,
	180,	WAIT_32,
	170,	WAIT_32,
	160,	WAIT_32,
	150,	WAIT_32,
	140,	WAIT_32,
	130,	WAIT_8
};

//could also be put in the flash, but don't care at the moment
const uint16_t songlist[] = {
	// pointer to the near flash	//length of track			//play in dur 1 - 6 (1 MHz optimized)
	(uint16_t)wedding_march,		sizeof(wedding_march),		3,
	(uint16_t)fuer_elise,			sizeof(fuer_elise),			4,
	(uint16_t)chirp,				sizeof(chirp),				4,
	(uint16_t)chirp2,				sizeof(chirp2),				4,
	(uint16_t)upscale,				sizeof(upscale),			5
	
};