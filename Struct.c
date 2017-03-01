/***********************************************\
*												*
* Struct.c										*
*	Team 5										*
*	1/14/13 Justin Hempsey: Initial Creation	*
*												*
* 	Contains the initial structures and			*
*	structure management.						*
*												*
\***********************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "Constants.h"
#include "Struct.h"

/* Create a new chess board in memory */
BOARD *NewBoard(void)
{
	BOARD *rtnBoard = NULL;
	rtnBoard = calloc(1, sizeof(BOARD));	/* Callocs the board */
		if (!(rtnBoard))					/* Checks for proper memory allocation */
		{
			printf("ERROR: Memory allocation error.\n");
			#ifdef DEBUG
				printf("Error in board memory allocation. \n");
			#endif
			exit(10);
		}
	/* Initializes board structure values */	
	memcpy(rtnBoard->Position, NULL_BOARD, sizeof(rtnBoard->Position));
	
	return rtnBoard;
}

/* Deletes a chess board from memory */
void DeleteBoard(BOARD *Board)
{
	unsigned char i, j;
	assert(Board);
	
	for (i = 0; i < 8; i++){
		for (j = 0; j < 8; j++)
		{
			if (Board->Position[i][j]) DeletePiece(Board->Position[i][j]);
		}
	}
		
	memcpy(Board->Position, NULL_BOARD, sizeof(Board->Position));

	/* Deletes the board passed to function and resets all of the memory that was used*/
	/* Board->Position = 0; */
	
	free(Board);
}

/* Allocates memory for a piece */
PIECE *NewPiece(void)
{
	PIECE *rtnPiece = NULL;
	
	rtnPiece = calloc(1, sizeof(PIECE));
	if (!(rtnPiece))					/* Checks for proper memory allocation */
	{
		printf("ERROR: Memory allocation error.\n");
		#ifdef DEBUG
			printf("Error in Piece memory allocation. \n");
		#endif
		exit(10);
	}
		
	rtnPiece->Piece = none;
	rtnPiece->Player = noplayer;
	rtnPiece->Captured = no;
	rtnPiece->MoveCount = 0;
	rtnPiece->x = 0;
	rtnPiece->y = 0;
	rtnPiece->Next = NULL;
	return rtnPiece;
}
/*Deletes a piece from memory */
void DeletePiece(PIECE *Piece)
{
	assert(Piece);
	
	Piece->Piece = noplayer;
	Piece->Player = white;
	Piece->Captured = no;
	Piece->MoveCount = 0;
	Piece->x = 0;
	Piece->y = 0;
	if (Piece->Next) DeleteNextMoves(Piece->Next);
	free(Piece);
}

/* Generates an array of valid moves for a piece */
NEXTMOVES *NewNextMoves(PIECE *Piece)
{
	NEXTMOVES *rtnMoves = NULL;
	
	rtnMoves = calloc(1, sizeof(NEXTMOVES));
	if (!(rtnMoves))					/* Checks for proper memory allocation */
		{
			printf("ERROR: Memory allocation error.\n");
			#ifdef DEBUG
				printf("Error in NextMove memory allocation. \n");
			#endif
			exit(10);
		}
	/* Initializes board structure values */
	rtnMoves->Piece = Piece;
	memcpy(rtnMoves->Valid, EMPTY_STATUS, sizeof(rtnMoves->Valid));
	return rtnMoves;
}

/* Deletes a piece's valid next move array */
void DeleteNextMoves(NEXTMOVES *Next)
{
	assert(Next);
	
	Next->Piece = NULL;
	memcpy(Next->Valid, EMPTY_STATUS, sizeof(Next->Valid));
	
	free(Next);
}