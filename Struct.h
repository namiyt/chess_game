/***********************************************\
*												*
* struct.h										*
*	Team 5										*
*	1/12/13 Justin Hempsey: Initial Creation	*
*												*
* 	Contains the initial structures and			*
*	structure management.						*
*												*
\***********************************************/

#include <stdlib.h>

#ifndef STRUCT_H
#define STRUCT_H

typedef struct 	PieceStruct 	PIECE;		/* Individual piece structure */	
typedef struct 	BoardStruct	BOARD;		/* Board structure for piece locations */
typedef struct 	NextMoveStruct	NEXTMOVES;	/* Structure for a piece's next moves */		

/*** ENUMS ***/
/* Player color enum */
typedef enum
{
	noplayer = 0,		/* For initialization */
	white = -1,
	black = 1
} t_player;

/* Each piece and an associated value for AI implementation */			
typedef enum 
{	
	none 	= 0,
	pawn 	= 1,
	knight 	= 3,
	bishop 	= 5,
	rook 	= 7,
	queen 	= 10,
	king 	= 100
} t_piece;			

/* Piece captured status */
typedef enum 
{
	no = 0,
	yes = 1
} t_status;	

/*** STRUCTURES ***/
struct PieceStruct 					/* Individual piece structure */
{
	t_piece Piece;
	t_player Player;
	t_status Captured;
	unsigned char MoveCount;
	unsigned char x;				/* Cooridinates of piece on board */
	unsigned char y;
	NEXTMOVES *Next;
};

struct BoardStruct					/* Board Structure */
{
/* 	t_piece Position [8][8];  */
 	PIECE *Position [8][8]; 
};

struct NextMoveStruct				/*  Valid next moves */
{	
	PIECE *Piece;
	t_status Valid[8][8];		/* Fake board of legal next moves. */
};

/*** FUNCTIONS ***/
/* Create a new chess board in memory */
BOARD *NewBoard(void);
/* Deletes a chess board from memory */
void DeleteBoard(BOARD *Board);
/* Allocates memory for a piece */
PIECE *NewPiece(void);
/*Deletes a piece from memory */
void DeletePiece(PIECE *Piece);
/* Allocates memory for valid moves for a piece */
NEXTMOVES *NewNextMoves(PIECE *Piece);
/* Deletes a piece's valid next move array */
void DeleteNextMoves(NEXTMOVES *Next);

#endif
