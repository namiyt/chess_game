/***********************************************\
*												*
* Functions.c									*
*	Team 5										*
*	1/13/13 Justin Hempsey: Initial Creation	*
*												*
* 	Contains the piece functions				*
*		FILE WILL PROBABLY BE RENAMED			*
*												*
\***********************************************/

#include <stdio.h>
#include <stdlib.h>
#include "Struct.h"
#include "Functions.h"


/** Moves a piece in memory */ 
void MovePiece(BOARD *Board, unsigned char x1, unsigned char y1, unsigned char x2, unsigned char y2)
{

}

/** Returns an address of a piece if current piece is moved to that location,  NULL otherwise**/
void CheckNextMove(PIECE *Piece, BOARD *Board, NEXTMOVES *ValidBoard){
	int flag1,flag2,flag3,flag4;
	
	if(Piece->Piece == bishop){
		int x_in = Piece->x;
		int y_in = Piece->y;
		
		int x = x_in;
		int y = y_in;
		while((x < 8)&&(y > 0)){
			if((Board->Position[x][y] != NULL)&&(ValidBoard->Valid[x][y]== yes)&&(flag1 != 1)){
				flag1 = 1;
			}
			if((ValidBoard->Valid[x][y] == yes)&&(flag1 == 1)){
				ValidBoard->Valid[x][y] = no;	
			}
			x++;
			y--;
		}
		x = x_in;
		y = y_in;
		while((x > 0)&&(y > 0)){
			if((Board->Position[x][y] != NULL)&&(ValidBoard->Valid[x][y]== yes)&&(flag2 != 1)){
				flag2 = 1;
			}
			if((ValidBoard->Valid[x][y] == yes)&&(flag2 == 1)){
				ValidBoard->Valid[x][y] = no;	
			}
			x--;
			y--;
		}	
		x = x_in;
		y = y_in;
		while((x < 8)&&(y < 8)){
			if((Board->Position[x][y] != NULL)&&(ValidBoard->Valid[x][y]== yes)&&(flag3 != 1)){
				flag3 = 1;
			}
			if((ValidBoard->Valid[x][y] == yes)&&(flag3 == 1)){
				ValidBoard->Valid[x][y] = no;	
			}
			x++;
			y++;
		}	
		x = x_in;
		y = y_in;
		while((x > 0)&&(y < 8)){
			if((Board->Position[x][y] != NULL)&&(ValidBoard->Valid[x][y]== yes)&&(flag4 != 1)){
				flag4 = 1;
			}
			if((ValidBoard->Valid[x][y] == yes)&&(flag4 == 1)){
				ValidBoard->Valid[x][y] = no;	
			}
			x--;
			y++;
		}	
	}
	if(Piece->Piece == knight){

	}
	if(Piece->Piece == queen){

	}

}

/** Generates a board of possible valid moves for the piece passed to the function. **/
NEXTMOVES *GenerateValidMoves(BOARD *Board, PIECE *Piece)
{
	unsigned char x, y, direction;
	signed 	 char i;
	NEXTMOVES *ValidBoard;						/*Board containg the valid moves*/
	
	ValidBoard = NewNextMoves(Piece);			/*Create Function*/

	x = Piece->x;
	y = Piece->y;
	
	switch (Piece->Piece)
	{
		/*Pawn case statement*/
		/*-------------------------------------------*/
		case pawn:
			if ((Piece->Player = black)) direction = 1;		/* Black moves down the board, White moves up */
			if ((Piece->Player = white)) direction = -1;

			ValidBoard->Valid[x][y + (direction * 1)] = yes;
			if (Piece->MoveCount < 1)						/* Pawn has not moved yet it can go two spaces */
			{
				ValidBoard->Valid[x][y + (direction * 2)] = yes;
			}
		break;
		
		case knight:
			ValidBoard->Valid[0][0] = yes;
			if ((x + 2) < 8 && (y + 1) < 8) 	ValidBoard->Valid[x + 2][y + 1] = yes;
			if ((x - 2) >= 0 && (y + 1) < 8) 	ValidBoard->Valid[x - 2][y + 1] = yes;
			if ((x + 2) < 8 && (y - 1) >= 0) 	ValidBoard->Valid[x + 2][y - 1] = yes;
			if ((x - 2) >= 0 && (y - 1) >= 0) 	ValidBoard->Valid[x - 2][y - 1] = yes;
			if ((x + 1) < 8 && (y + 2) < 8) 	ValidBoard->Valid[x + 1][y + 2] = yes;
			if ((x - 1) >= 0 && (y + 2) < 8) 	ValidBoard->Valid[x - 1][y + 2] = yes;
			if ((x + 1) < 8 && (y - 2) >= 0) 	ValidBoard->Valid[x + 1][y - 2] = yes;
			if ((x - 1) >= 0 && (y - 2) >= 0) 	ValidBoard->Valid[x - 1][y - 2] = yes;
		break; 
		
		case bishop:
			for (i = -8; i < 8; i++){
				if (((x + i) >= 0 && (x + i) < 8) && ((y + i) >= 0 && (y + i) < 8)) {
					ValidBoard->Valid[x + i][y + i] = yes;
				}
			}
		break;
		
		case rook:
			/* Horizontal */
			for (i = -8; i < 8; i++){
				if (((x + i) >= 0 && (x + i) < 8)) {
					ValidBoard->Valid[x + i][y] = yes;
				}
			}
			/* Vertical */
			for (i = -8; i < 8; i++){
				if (((y + i) >= 0 && (y + i) < 8)) {
					ValidBoard->Valid[x][y + i] = yes;
				}
			}
		break;
		
		case queen:
			/* Diagonal */
			for (i = -8; i < 8; i++){
				if (((x + i) >= 0 && (x + i) < 8) && ((y + i) >= 0 && (y + i) < 8)) {
					ValidBoard->Valid[x +i][y + i] = yes;
				}
			}
			/* Horizontal */
			for (i = -8; i < 8; i++){
				if (((x + i) >= 0 && (x + i) < 8)) {
					ValidBoard->Valid[x + i][y] = yes;
				}
			}
			/* Vertical */
			for (i = -8; i < 8; i++){
				if (((y + i) >= 0 && (y + i) < 8)) {
					ValidBoard->Valid[x][y + i] = yes;
				}
			}
		break;
		
		case king:
			if ((y + 1) < 8 && (x + 1) < 8) ValidBoard->Valid[y + 1][x + 1] = yes;
			if ((y - 1) >= 0 && (x + 1) < 8) ValidBoard->Valid[y - 1][x + 1] = yes;
			if ((y + 1) < 8 && (x - 1) >= 0) ValidBoard->Valid[y + 1][x - 1] = yes;
			if ((y - 1) >= 0 && (x - 1) >= 0) ValidBoard->Valid[y - 1][x - 1] = yes;
			if (x + 1 < 8) ValidBoard->Valid[x + 1][y] = yes;
			if (y + 1 < 8) ValidBoard->Valid[x][y +1] = yes;
			if (x - 1 >= 0) ValidBoard->Valid[x - 1][y] = yes;
			if (y - 1 >= 0) ValidBoard->Valid[x][y - 1] = yes;
		break;
		
		default:
			/*DO NOTHING*/
		break;
	}
	
	return ValidBoard;
}

/** Intializes the chess board in memory **/
BOARD *InitializeBoard (void)
{
	unsigned char i, j;

	BOARD *rtnBoard = NULL;
	
	rtnBoard = NewBoard();
	
	/* WHITE PLAYER'S PIECES */
	/* Pawn */
	for (i = 0; i < 8; i++)
	{
		rtnBoard->Position[i][6] = NewPiece();
		rtnBoard->Position[i][6]->Piece = pawn;
		rtnBoard->Position[i][6]->x = i;
		rtnBoard->Position[i][6]->y = 6;
		rtnBoard->Position[i][6]->Next = GenerateValidMoves(rtnBoard, rtnBoard->Position[i][6]);
	} 

	/* Rooks */
	rtnBoard->Position[0][7] = NewPiece();
	rtnBoard->Position[0][7]->Piece = rook;
	rtnBoard->Position[0][7]->x = 0;
	rtnBoard->Position[0][7]->y = 7;
	rtnBoard->Position[0][7]->Next = GenerateValidMoves(rtnBoard, rtnBoard->Position[0][7]);

	rtnBoard->Position[7][7] = NewPiece();
	rtnBoard->Position[7][7]->Piece = rook;
	rtnBoard->Position[7][7]->x = 7;
	rtnBoard->Position[7][7]->y = 7;
	rtnBoard->Position[7][7]->Next = GenerateValidMoves(rtnBoard, rtnBoard->Position[7][7]);

	/* Knights  */
	rtnBoard->Position[1][7] = NewPiece();
	rtnBoard->Position[1][7]->Piece = knight;
	rtnBoard->Position[1][7]->x = 1;
	rtnBoard->Position[1][7]->y = 7;
	rtnBoard->Position[1][7]->Next = GenerateValidMoves(rtnBoard, rtnBoard->Position[1][7]);

	rtnBoard->Position[6][7] = NewPiece();
	rtnBoard->Position[6][7]->Piece = knight;
	rtnBoard->Position[6][7]->x = 6;
	rtnBoard->Position[6][7]->y = 7;
	rtnBoard->Position[6][7]->Next = GenerateValidMoves(rtnBoard, rtnBoard->Position[6][7]);

	/* Bishops  */
	rtnBoard->Position[2][7] = NewPiece();
	rtnBoard->Position[2][7]->Piece = bishop;
	rtnBoard->Position[2][7]->x = 2;
	rtnBoard->Position[2][7]->y = 7;
	rtnBoard->Position[2][7]->Next = GenerateValidMoves(rtnBoard, rtnBoard->Position[2][7]);

	rtnBoard->Position[5][7] = NewPiece();
	rtnBoard->Position[5][7]->Piece = bishop;
	rtnBoard->Position[5][7]->x = 5;
	rtnBoard->Position[5][7]->y = 7;
	rtnBoard->Position[5][7]->Next = GenerateValidMoves(rtnBoard, rtnBoard->Position[5][7]);

	/* Queen */
	rtnBoard->Position[3][7] = NewPiece();
	rtnBoard->Position[3][7]->Piece = queen;
	rtnBoard->Position[3][7]->x = 3;
	rtnBoard->Position[3][7]->y = 7;
	rtnBoard->Position[3][7]->Next = GenerateValidMoves(rtnBoard, rtnBoard->Position[3][7]);

	/* King */
	rtnBoard->Position[4][7] = NewPiece();
	rtnBoard->Position[4][7]->Piece = king;
	rtnBoard->Position[4][7]->x = 5;
	rtnBoard->Position[4][7]->y = 7;
	rtnBoard->Position[4][7]->Next = GenerateValidMoves(rtnBoard, rtnBoard->Position[4][7]);

	/* Set Player and Captured status-- White */
	for (i = 0; i < 8; i++){
		for (j = 6; j < 8; j++)
		{
			rtnBoard->Position[i][j]->Captured = no;
			rtnBoard->Position[i][j]->Player = white; 
		}
	}

	/* BLACK PLAYER'S PIECES */
	/* Pawn */
	for (i = 0; i < 8; i++)
	{
		rtnBoard->Position[i][1] = NewPiece();
		rtnBoard->Position[i][1]->Piece = pawn;
		rtnBoard->Position[i][1]->x = i;
		rtnBoard->Position[i][1]->y = 6;
		rtnBoard->Position[i][1]->Next = GenerateValidMoves(rtnBoard, rtnBoard->Position[i][1]);
	} 

	/* Rooks */
	rtnBoard->Position[0][0] = NewPiece();
	rtnBoard->Position[0][0]->Piece = rook;
	rtnBoard->Position[0][0]->x = 0;
	rtnBoard->Position[0][0]->y = 7;
	rtnBoard->Position[0][0]->Next = GenerateValidMoves(rtnBoard, rtnBoard->Position[0][0]);

	rtnBoard->Position[7][0] = NewPiece();
	rtnBoard->Position[7][0]->Piece = rook;
	rtnBoard->Position[7][0]->x = 7;
	rtnBoard->Position[7][0]->y = 7;
	rtnBoard->Position[7][0]->Next = GenerateValidMoves(rtnBoard, rtnBoard->Position[7][0]);

	/* Knights */
	rtnBoard->Position[1][0] = NewPiece();
	rtnBoard->Position[1][0]->Piece = knight;
	rtnBoard->Position[1][0]->x = 1;
	rtnBoard->Position[1][0]->y = 7;
	rtnBoard->Position[1][0]->Next = GenerateValidMoves(rtnBoard, rtnBoard->Position[1][0]);

	rtnBoard->Position[6][0] = NewPiece();
	rtnBoard->Position[6][0]->Piece = knight;
	rtnBoard->Position[6][0]->x = 6;
	rtnBoard->Position[6][0]->y = 7;
	rtnBoard->Position[6][0]->Next = GenerateValidMoves(rtnBoard, rtnBoard->Position[6][0]);

	/* Bishops */
	rtnBoard->Position[2][0] = NewPiece();
	rtnBoard->Position[2][0]->Piece = bishop;
	rtnBoard->Position[2][0]->x = 2;
	rtnBoard->Position[2][0]->y = 7;
	rtnBoard->Position[2][0]->Next = GenerateValidMoves(rtnBoard, rtnBoard->Position[2][0]);

	rtnBoard->Position[5][0] = NewPiece();
	rtnBoard->Position[5][0]->Piece = bishop;
	rtnBoard->Position[5][0]->x = 5;
	rtnBoard->Position[5][0]->y = 7;
	rtnBoard->Position[5][0]->Next = GenerateValidMoves(rtnBoard, rtnBoard->Position[5][0]);

	/* Queen */
	rtnBoard->Position[3][0] = NewPiece();
	rtnBoard->Position[3][0]->Piece = queen;
	rtnBoard->Position[3][0]->x = 3;
	rtnBoard->Position[3][0]->y = 7;
	rtnBoard->Position[3][0]->Next = GenerateValidMoves(rtnBoard, rtnBoard->Position[3][0]);

	/* King */
	rtnBoard->Position[4][0] = NewPiece();
	rtnBoard->Position[4][0]->Piece = king;
	rtnBoard->Position[4][0]->x = 5;
	rtnBoard->Position[4][0]->y = 7;
	rtnBoard->Position[4][0]->Next = GenerateValidMoves(rtnBoard, rtnBoard->Position[4][0]);
	
	/* Set Player and Captured status-- Black */

	/* Set Player and Captured status */
	for (i = 0; i < 8; i++){
		for (j = 0; j < 2; j++)
		{
			rtnBoard->Position[i][j]->Captured = no;
			rtnBoard->Position[i][j]->Player = black; 
		}
	}
	
	return rtnBoard;
}


/* Test function */
int main()
{
	BOARD *Board = NULL;
	
	Board = InitializeBoard();
	
	
	
	DeleteBoard(Board);
	return 0;
}

