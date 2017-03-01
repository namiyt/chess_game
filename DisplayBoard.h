/***********************************************\
*												*
* DisplayBoard.h								*
*	Team 5										*
*	1/22/14 Aaron Chen							*
*		-added initial Display, PieceType, 		*
*		and PieceColor structures				*
*												*
*												*
\***********************************************/

#include <stdlib.h>

#ifndef STRUCT_H
#define STRUCT_H

/*Display the board*/
int Display(void);

/*Determine Piece type*/
char PieceType(PIECE *Piece);

/*Determine Piece color*/
char PieceColor();

#endif
