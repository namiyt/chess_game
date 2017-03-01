/***********************************************\
*												*
* Constants.h									*
*	Team 5										*
*	1/16/13 Justin Hempsey: Initial Creation	*
*												*
* 	Contains various constants for all modules. *
*												*
\***********************************************/

#include "Struct.h"

#ifndef CONSTANTS_H
#define CONSTANTS_H

/*const t_piece INITIAL_BOARD[8][8] = {
	{rook,	knight,	bishop,	queen,	king, 	bishop, knight, rook},
	{pawn,	pawn,	pawn,	pawn,	pawn,	pawn,	pawn,	pawn},
	{none,	none,	none,	none,	none,	none,	none,	none},
	{none,	none,	none,	none,	none,	none,	none,	none},
	{none,	none,	none,	none,	none,	none,	none,	none},
	{none,	none,	none,	none,	none,	none,	none,	none},
	{pawn,	pawn,	pawn,	pawn,	pawn,	pawn,	pawn,	pawn},
	{rook,	knight,	bishop,	queen,	king, 	bishop, knight, rook},
};*/

const PIECE **NULL_BOARD[8][8] = {
	{NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
	{NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
	{NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
	{NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
	{NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
	{NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
	{NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL},
	{NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL}
};

const t_status	EMPTY_STATUS[8][8] = {
	{no, no, no, no, no, no, no, no},
	{no, no, no, no, no, no, no, no},
	{no, no, no, no, no, no, no, no},
	{no, no, no, no, no, no, no, no},
	{no, no, no, no, no, no, no, no},
	{no, no, no, no, no, no, no, no},
	{no, no, no, no, no, no, no, no},
	{no, no, no, no, no, no, no, no},
};
#endif