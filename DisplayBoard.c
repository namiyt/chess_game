/* **********************************************
*												*
* DisplayBoard.c								*
*	Team 5										*
*	Aaron Chen									*
*	Namirud Yegezu								*
*	Lennard Lau									*
*												*
* 	GUI for the chess game						*
*												*
********************************************** */

#include "Struct.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "DisplayBoard.h"

/*displays the board*/
int Display(BOARD *B)
{

	int i,j;

	for(i=0; i<8; i++)
	{
		printf("  +----+----+----+----+----+----+----+----+\n");
		printf("%d ", 8-j);
		for(j=0; j<8; j++)
		{
			if((B->Position[i][j] != NULL))
			{
				printf("| %c  ", DetName(B->Position[i][j]));  
			}
			else
			{
				printf("| ");
			}
		}
	printf("| \n");
	}
	printf("     a    b    c    d    e    f    g    h  \n");
	return 0;
}
	


/*determine the chess piece type*/
char PieceType(PIECE *P)
{
	switch(P->Piece)
	{
		case none:
			return ' ';
			break;
		case pawn:
			return 'P';
			break;
		case knight:
			return 'N';
			break;
		case bishop:
			return 'B';
			break;
		case rook:
			return 'R';
			break;
		case queen:
			return 'Q';
			break;
		case king:
			return 'K';
			break;
	}
	return 0;
}

/*determine whether piece is white or black*/
char PieceColor(PIECE *P)
{
	switch(P->Player)
	{
		case noplayer:
			return ' ';
			break;			
		case white:
			return 'w';
			break;
		case black:
			return 'b';
			break;
	}
	return 0;
}

/*determines the name of the piece*/
char DetName(PIECE *P)
{
	return printf("%c%c", PieceType(P), PieceColor(P));
}