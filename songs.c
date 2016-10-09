/*
 * songs.c
 *
 * Created: 10.03.2016 15:58:08
 *  Author: Sebastian Foerster
 *	Web:	sebastianfoerster86.wordpress.com
 *	License: GPLv2
 */ 

#include <avr/pgmspace.h>
#include "sound.h"
#include "songs.h"


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
#define B		(H)

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
#define H2		(127/2)
#define B2		(H2)

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

const uint8_t PROGMEM o_du_froehliche[] = {
	G,		WAIT_2,
	A,		WAIT_2,
	G,		WAIT_4,
	F,		WAIT_8,
	E,		WAIT_4,
	F,		WAIT_4,
	G,		WAIT_2,
	A,		WAIT_2,
	G,		WAIT_4,
	F,		WAIT_8,
	E,		WAIT_4,
	F,		WAIT_4,
	G,		WAIT_2,
	G,		WAIT_2,
	A,		WAIT_2,
	B,		WAIT_4,
	C2,		WAIT_4,
	B,		WAIT_2,
	A,		WAIT_2,
	G,		WAIT_1,
	PAUSE,	WAIT_8,
	D,		WAIT_4_D,
	E,		WAIT_8,
	D,		WAIT_4,
	E,		WAIT_4,
	F,		WAIT_4_D,
	G,		WAIT_8,
	F,		WAIT_2,
	E,		WAIT_4_D,
	F,		WAIT_8,
	E,		WAIT_4,
	F,		WAIT_8,
	G,		WAIT_4_D,
	A,		WAIT_8,
	G,		WAIT_2,
	PAUSE,	WAIT_8,
	C2,		WAIT_4,
	B,		WAIT_4,
	A,		WAIT_4,
	G,		WAIT_4,
	C2,		WAIT_4,
	A,		WAIT_4,
	G,		WAIT_4,
	F,		WAIT_4,
	E,		WAIT_2,
	D,		WAIT_2,
	C,		WAIT_1,
	PAUSE,	WAIT_8
};

const uint8_t PROGMEM leise_rieselt_der_schnee[] = {
	A2,		WAIT_2,
	A2,		WAIT_4,
	G2,		WAIT_4,
	A2,		WAIT_4,
	G2,		WAIT_4,
	F2,		WAIT_1_D,
	PAUSE,	WAIT_8,
	F2,		WAIT_2,
	D2,		WAIT_4,
	F2,		WAIT_4,
	E2,		WAIT_4,
	D2,		WAIT_4,
	C2,		WAIT_1_D,
	PAUSE,	WAIT_8,
	G2,		WAIT_4,
	FS2,	WAIT_4,
	G2,		WAIT_4,
	A2,		WAIT_4,
	A2,		WAIT_4,
	G2,		WAIT_4,
	F2,		WAIT_1_D,
	PAUSE,	WAIT_8,
	G2,		WAIT_4_D,
	D2,		WAIT_8,
	D2,		WAIT_4,
	E2,		WAIT_4,
	D2,		WAIT_4,
	E2,		WAIT_4,
	F2,		WAIT_1_D,
	PAUSE,	WAIT_8

};

const uint8_t PROGMEM froehliche_weihnacht_ueberall[] = {
	C2,		WAIT_8,
	B,		WAIT_8,
	A,		WAIT_8,
	B,		WAIT_8,
	C2,		WAIT_4,
	A,		WAIT_4,
	F,		WAIT_4,
	G,		WAIT_4,
	A,		WAIT_2,
	A,		WAIT_8,
	G,		WAIT_8,
	F,		WAIT_8,
	G,		WAIT_8,
	A,		WAIT_4,
	F,		WAIT_4,
	C,		WAIT_4,
	E,		WAIT_4,
	F,		WAIT_2,
	G,		WAIT_4,
	C2,		WAIT_4,
	C2,		WAIT_2,
	A,		WAIT_4,
	C2,		WAIT_4,
	C2,		WAIT_2,
	G,		WAIT_4,
	D2,		WAIT_4,
	C2,		WAIT_4,
	A,		WAIT_4,
	C2,		WAIT_4,
	B,		WAIT_8,
	A,		WAIT_8,
	G,		WAIT_2,
	C2,		WAIT_8,
	B,		WAIT_8,
	A,		WAIT_8,
	B,		WAIT_8,
	C2,		WAIT_4,
	A,		WAIT_4,
	F,		WAIT_4,
	G,		WAIT_4,
	A,		WAIT_2,
	A,		WAIT_8,
	G,		WAIT_8,
	F,		WAIT_8,
	G,		WAIT_8,
	A,		WAIT_4,
	F,		WAIT_4,
	C,		WAIT_4,
	E,		WAIT_4,
	F,		WAIT_2,
	G,		WAIT_4_D,
	A,		WAIT_8,
	AS,		WAIT_4,
	G,		WAIT_4,
	A,		WAIT_4,
	H,		WAIT_4,
	C2,		WAIT_2,
	D2,		WAIT_4,
	C2,		WAIT_4,
	H,		WAIT_4,
	A,		WAIT_4,
	AS,		WAIT_2_D,
	PAUSE,	WAIT_8,
	G,		WAIT_4_D,
	A,		WAIT_8,
	AS,		WAIT_4,
	G,		WAIT_4,
	A,		WAIT_4,
	AS,		WAIT_4,
	C2,		WAIT_2,
	C,		WAIT_4,
	A,		WAIT_4,
	A,		WAIT_4,
	G,		WAIT_4,
	F,		WAIT_2_D,
	PAUSE,	WAIT_8
};

const uint8_t PROGMEM zum_geburtstag_viel_glueck[] = {
	G,		WAIT_8,
	G,		WAIT_16,
	A,		WAIT_4,
	G,		WAIT_4,
	C2,		WAIT_4,
	H,		WAIT_2,
	G,		WAIT_8,
	G,		WAIT_16,
	A,		WAIT_4,
	G,		WAIT_4,
	D2,		WAIT_4,
	C2,		WAIT_4,
	G,		WAIT_8,
	G,		WAIT_16,
	G2,		WAIT_4,
	E2,		WAIT_4,
	C2,		WAIT_8,
	C2,		WAIT_16,
	H,		WAIT_4,
	A,		WAIT_4,
	F2,		WAIT_8,
	F2,		WAIT_16,
	E2,		WAIT_4,
	C2,		WAIT_4,
	D2,		WAIT_4,
	C2,		WAIT_2,
	PAUSE,	WAIT_1,
	G,		WAIT_8,
	G,		WAIT_16,
	A,		WAIT_4,
	G,		WAIT_4,
	C2,		WAIT_4,
	H,		WAIT_2,
	G,		WAIT_8,
	G,		WAIT_16,
	A,		WAIT_4,
	G,		WAIT_4,
	D2,		WAIT_4,
	C2,		WAIT_4,
	G,		WAIT_8,
	G,		WAIT_16,
	G2,		WAIT_4,
	E2,		WAIT_4,
	C2,		WAIT_8,
	C2,		WAIT_16,
	H,		WAIT_4,
	A,		WAIT_4,
	F2,		WAIT_8,
	F2,		WAIT_16,
	E2,		WAIT_4,
	C2,		WAIT_4,
	D2,		WAIT_4,
	C2,		WAIT_2
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

const uint8_t PROGMEM batman_theme[] = {
	C2,		WAIT_16,
	C2,		WAIT_16,
	H,		WAIT_16,
	H,		WAIT_16,
	AS,		WAIT_16,
	AS,		WAIT_16,
	H,		WAIT_16,
	H,		WAIT_16,
	C2,		WAIT_16,
	C2,		WAIT_16,
	H,		WAIT_16,
	H,		WAIT_16,
	AS,		WAIT_16,
	AS,		WAIT_16,
	H,		WAIT_16,
	H,		WAIT_16,
	C2,		WAIT_4,
	C2,		WAIT_4_D,
	PAUSE,	WAIT_1
	
};

//could also be put in the flash, but don't care at the moment
uint16_t songlist[NUMBER_OF_SONGS * 3] = {
	// pointer to the near flash	//length of track			//play in octave 1 - 6 (1 MHz optimized)
	(uint16_t)o_du_froehliche,					sizeof(o_du_froehliche),				4,
	//(uint16_t)fuer_elise,						sizeof(fuer_elise),						4,
	(uint16_t)froehliche_weihnacht_ueberall,	sizeof(froehliche_weihnacht_ueberall),	4,
	//(uint16_t)upscale,						sizeof(upscale),						5,
	(uint16_t)leise_rieselt_der_schnee,			sizeof(leise_rieselt_der_schnee),		3,
	(uint16_t)zum_geburtstag_viel_glueck,		sizeof(zum_geburtstag_viel_glueck),		4
	
};