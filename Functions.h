/***********************************************\
*												*
* Functions.h									*
*	Team 5										*
*	1/13/13 Justin Hempsey: Initial Creation	*
*												*
* 	Contains the piece functions				*
*		FILE WILL PROBABLY BE RENAMED			*
*												*
\***********************************************/

#ifndef FUNCTIONS_H
#define FUNCTION_H

NEXTMOVES *GenerateValidMoves(BOARD *Board, PIECE *Piece);

BOARD *InitializeBoard (void);

void MovePiece(BOARD *Board, unsigned char x1, unsigned char y1, unsigned char x2, unsigned char y2);


#endif
