
#include "stdlib.h"
#include "SDL/SDL.h"
#include <stdio.h>

#define EVENTS		/* process events and wait for window close */

void main(int argc, char *argv[])
{
	SDL_Surface *screen;	/*This pointer will reference the backbuffer*/
	SDL_Surface *image;	/*This pointer will reference our bitmap sprite*/

	SDL_Surface *PieceKingWhite, *PieceQueenWhite, *PieceRookWhite, *PieceBishopWhite, *PieceKnightWhite, *PiecePawnWhite;
	SDL_Surface *PieceKingBlack, *PieceQueenBlack, *PieceRookBlack, *PieceBishopBlack, *PieceKnightBlack, *PiecePawnBlack;
	SDL_Surface *BoardWhite, *BoardBlack;

	SDL_Rect src, dest;	/*These rectangles will describe the source and destination regions of our blit*/
	int x,y;

	int ColA, ColB, ColC, ColD, ColE, ColF, ColG, ColH;  /* Column Corrdinate For Algebraic notation*/	
	int Row1, Row2, Row3, Row4, Row5, Row6, Row7, Row8;  /* Row Corrdinate For Algebraic notation	*/

#ifdef EVENTS
	SDL_Event event;	/* Event structure */
	int Running;
#endif

	/*We must first initialize the SDL video component, and check for success*/
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		printf("Unable to initialize SDL: %s\n", SDL_GetError());
		return 1;
	}
	
	/*When this program exits, SDL_Quit must be called*/
	atexit(SDL_Quit);
	
	/*Set the video mode to a window of size 1024 by 768 pixels with 32 bits per pixel*/
	screen = SDL_SetVideoMode(1024, 768, 32, SDL_ANYFORMAT /*SDL_DOUBLEBUF | SDL_FULLSCREEN*/);
	if (screen == NULL) {
		printf("Unable to set video mode: %s\n", SDL_GetError());
		return 1;
	}
	
	/*Load the White Piece bitmaps, and check for success*/
	PieceKingWhite = SDL_LoadBMP("PieceKingWhite.bmp");
	if (PieceKingWhite == NULL) {
		printf("Unable to load bitmap: %s\n", SDL_GetError());
		return 1;
	}

	PieceQueenWhite = SDL_LoadBMP("PieceQueenWhite.bmp");
	if (PieceQueenWhite == NULL) {
		printf("Unable to load bitmap: %s\n", SDL_GetError());
		return 1;
	}
	
	PieceRookWhite = SDL_LoadBMP("PieceRookWhite.bmp");
	if (PieceRookWhite == NULL) {
		printf("Unable to load bitmap: %s\n", SDL_GetError());
		return 1;
	}

	PieceBishopWhite = SDL_LoadBMP("PieceBishopWhite.bmp");
	if (PieceBishopWhite == NULL) {
		printf("Unable to load bitmap: %s\n", SDL_GetError());
		return 1;
	}

	PieceKnightWhite = SDL_LoadBMP("PieceKnightWhite.bmp");
	if (PieceKnightWhite == NULL) {
		printf("Unable to load bitmap: %s\n", SDL_GetError());
		return 1;
	}

	PiecePawnWhite = SDL_LoadBMP("PiecePawnWhite.bmp");
	if (PiecePawnWhite == NULL) {
		printf("Unable to load bitmap: %s\n", SDL_GetError());
		return 1;
	}

	/*Load the Black Piece bitmaps, and check for success*/
	PieceKingBlack = SDL_LoadBMP("PieceKingBlack.bmp");
	if (PieceKingBlack == NULL) {
		printf("Unable to load bitmap: %s\n", SDL_GetError());
		return 1;
	}

	PieceQueenBlack = SDL_LoadBMP("PieceQueenBlack.bmp");
	if (PieceQueenBlack == NULL) {
		printf("Unable to load bitmap: %s\n", SDL_GetError());
		return 1;
	}
	
	PieceRookBlack = SDL_LoadBMP("PieceRookBlack.bmp");
	if (PieceRookBlack == NULL) {
		printf("Unable to load bitmap: %s\n", SDL_GetError());
		return 1;
	}

	PieceBishopBlack = SDL_LoadBMP("PieceBishopBlack.bmp");
	if (PieceBishopBlack == NULL) {
		printf("Unable to load bitmap: %s\n", SDL_GetError());
		return 1;
	}

	PieceKnightBlack = SDL_LoadBMP("PieceKnightBlack.bmp");
	if (PieceKnightBlack == NULL) {
		printf("Unable to load bitmap: %s\n", SDL_GetError());
		return 1;
	}

	PiecePawnBlack = SDL_LoadBMP("PiecePawnBlack.bmp");
	if (PiecePawnBlack == NULL) {
		printf("Unable to load bitmap: %s\n", SDL_GetError());
		return 1;
	}

	/*Load the Board bitmaps, and check for success*/
	BoardWhite = SDL_LoadBMP("BoardWhite.bmp");
	if (BoardWhite == NULL) {
		printf("Unable to load bitmap: %s\n", SDL_GetError());
		return 1;
	}

	BoardBlack = SDL_LoadBMP("BoardBlack.bmp");
	if (BoardBlack == NULL) {
		printf("Unable to load bitmap: %s\n", SDL_GetError());
		return 1;
	}

	/* Make the background images of the pieces transparent to see the the square of chess board*/
	SDL_SetColorKey(PieceKingBlack, SDL_SRCCOLORKEY, SDL_MapRGB(PieceKingBlack->format,255,0, 255));
	SDL_SetColorKey(PieceQueenBlack, SDL_SRCCOLORKEY, SDL_MapRGB(PieceQueenBlack->format,255,0, 255));
	SDL_SetColorKey(PieceRookBlack, SDL_SRCCOLORKEY, SDL_MapRGB(PieceRookBlack->format,255,0, 255));
	SDL_SetColorKey(PieceBishopBlack, SDL_SRCCOLORKEY, SDL_MapRGB(PieceBishopBlack->format,255,0, 255));
	SDL_SetColorKey(PieceKnightBlack, SDL_SRCCOLORKEY, SDL_MapRGB(PieceKnightBlack->format,255,0, 255));
	SDL_SetColorKey(PiecePawnBlack, SDL_SRCCOLORKEY, SDL_MapRGB(PiecePawnBlack->format,255,0, 255));

	SDL_SetColorKey(PieceKingWhite, SDL_SRCCOLORKEY, SDL_MapRGB(PieceKingWhite->format,255,0, 255));
	SDL_SetColorKey(PieceQueenWhite, SDL_SRCCOLORKEY, SDL_MapRGB(PieceQueenWhite->format,255,0, 255));
	SDL_SetColorKey(PieceRookWhite, SDL_SRCCOLORKEY, SDL_MapRGB(PieceRookWhite->format,255,0, 255));
	SDL_SetColorKey(PieceBishopWhite, SDL_SRCCOLORKEY, SDL_MapRGB(PieceBishopWhite->format,255,0, 255));
	SDL_SetColorKey(PieceKnightWhite, SDL_SRCCOLORKEY, SDL_MapRGB(PieceKnightWhite->format,255,0, 255));
	SDL_SetColorKey(PiecePawnWhite, SDL_SRCCOLORKEY, SDL_MapRGB(PiecePawnWhite->format,255,0, 255));

	/*Convert the surface to the appropriate display format*/
	image = SDL_DisplayFormat(BoardWhite);
	
	/*Construct the source rectangle for our blit*/
	src.x = 0;
	src.y = 0;
	src.w = image->w;	/*Use image->w to display the entire width of the image*/
	src.h = image->h;	/*Use image->h to display the entire height of the image*/
	
	/*Construct the destination rectangle for our blit*/
	dest.x = 0;		/*Display the image at the (X,Y) coordinates (0,0)*/
	dest.y = 0;
	dest.w = image->w;	/*Ensure the destination is large enough for the image's entire width/height*/
	dest.h = image->h;
	

	/*draw chess board*/
	for(x=0; x<8; x++)	
	{
		for(y=0; y<8; y++)
			{
				if (y%2 == 0)
					{
						if (x%2 == 0)
				   			image = SDL_DisplayFormat(BoardWhite);
						else
				   			image = SDL_DisplayFormat(BoardBlack);
					}
				else
					{
						if (x%2 == 0)
				   			image = SDL_DisplayFormat(BoardBlack);
						else
				   			image = SDL_DisplayFormat(BoardWhite);
					}
				dest.x = x*image->w;
				dest.y = y*image->h;
				/*Blit the image to the backbuffer*/
				SDL_BlitSurface(image, &src, screen, &dest);
	
				/*Update the window at the modified region*/
				SDL_UpdateRect(screen, dest.x, dest.y, dest.w, dest.h);
			}
	}

	/* Translate Image location to Algebraic Notation*/
	ColA = 0*image->w;
	ColB = 1*image->w;
	ColC = 2*image->w;
	ColD = 3*image->w;
	ColE = 4*image->w;
	ColF = 5*image->w;
	ColG = 6*image->w;
	ColH = 7*image->w;

	Row8 = 0*image->h;
	Row7 = 1*image->h;
	Row6 = 2*image->h;
	Row5 = 3*image->h;
	Row4 = 4*image->h;
	Row3 = 5*image->h;
	Row2 = 6*image->h;
	Row1 = 7*image->h;

	/*Set up Pieces for Black side Row 8 of the chess board*/
	dest.y = Row8;
	
	dest.x = ColA;
	image = SDL_DisplayFormat(PieceRookBlack);
	SDL_BlitSurface(image, &src, screen, &dest);
	SDL_UpdateRect(screen, dest.x, dest.y, dest.w, dest.h);

	dest.x = ColB;
	image = SDL_DisplayFormat(PieceKnightBlack);
	SDL_BlitSurface(image, &src, screen, &dest);
	SDL_UpdateRect(screen, dest.x, dest.y, dest.w, dest.h);

	dest.x = ColC;
	image = SDL_DisplayFormat(PieceBishopBlack);
	SDL_BlitSurface(image, &src, screen, &dest);
	SDL_UpdateRect(screen, dest.x, dest.y, dest.w, dest.h);

	dest.x = ColD;
	image = SDL_DisplayFormat(PieceQueenBlack);
	SDL_BlitSurface(image, &src, screen, &dest);
	SDL_UpdateRect(screen, dest.x, dest.y, dest.w, dest.h);

	dest.x = ColE;
	image = SDL_DisplayFormat(PieceKingBlack);
	SDL_BlitSurface(image, &src, screen, &dest);
	SDL_UpdateRect(screen, dest.x, dest.y, dest.w, dest.h);

	dest.x = ColF;
	image = SDL_DisplayFormat(PieceBishopBlack);
	SDL_BlitSurface(image, &src, screen, &dest);
	SDL_UpdateRect(screen, dest.x, dest.y, dest.w, dest.h);

	dest.x = ColG;
	image = SDL_DisplayFormat(PieceKnightBlack);
	SDL_BlitSurface(image, &src, screen, &dest);
	SDL_UpdateRect(screen, dest.x, dest.y, dest.w, dest.h);

	dest.x = ColH;
	image = SDL_DisplayFormat(PieceRookBlack);
	SDL_BlitSurface(image, &src, screen, &dest);
	SDL_UpdateRect(screen, dest.x, dest.y, dest.w, dest.h);

	/*Set up Pieces for Black side Row 7 of the chess board*/
	dest.y = Row7;
	for(x=0; x<8; x++)  /*use for loop since all column are Pawns	*/
	{
		image = SDL_DisplayFormat(PiecePawnBlack);
		dest.x = x*image->w;
		SDL_BlitSurface(image, &src, screen, &dest);
		SDL_UpdateRect(screen, dest.x, dest.y, dest.w, dest.h);
	}

	/*Set up Pieces for White side Row 1 of the chess board*/
	dest.y = Row1;
	
	dest.x = ColA;
	image = SDL_DisplayFormat(PieceRookWhite);
	SDL_BlitSurface(image, &src, screen, &dest);
	SDL_UpdateRect(screen, dest.x, dest.y, dest.w, dest.h);

	dest.x = ColB;
	image = SDL_DisplayFormat(PieceKnightWhite);
	SDL_BlitSurface(image, &src, screen, &dest);
	SDL_UpdateRect(screen, dest.x, dest.y, dest.w, dest.h);

	dest.x = ColC;
	image = SDL_DisplayFormat(PieceBishopWhite);
	SDL_BlitSurface(image, &src, screen, &dest);
	SDL_UpdateRect(screen, dest.x, dest.y, dest.w, dest.h);

	dest.x = ColD;
	image = SDL_DisplayFormat(PieceQueenWhite);
	SDL_BlitSurface(image, &src, screen, &dest);
	SDL_UpdateRect(screen, dest.x, dest.y, dest.w, dest.h);

	dest.x = ColE;
	image = SDL_DisplayFormat(PieceKingWhite);
	SDL_BlitSurface(image, &src, screen, &dest);
	SDL_UpdateRect(screen, dest.x, dest.y, dest.w, dest.h);

	dest.x = ColF;
	image = SDL_DisplayFormat(PieceBishopWhite);
	SDL_BlitSurface(image, &src, screen, &dest);
	SDL_UpdateRect(screen, dest.x, dest.y, dest.w, dest.h);

	dest.x = ColG;
	image = SDL_DisplayFormat(PieceKnightWhite);
	SDL_BlitSurface(image, &src, screen, &dest);
	SDL_UpdateRect(screen, dest.x, dest.y, dest.w, dest.h);

	dest.x = ColH;
	image = SDL_DisplayFormat(PieceRookWhite);
	SDL_BlitSurface(image, &src, screen, &dest);
	SDL_UpdateRect(screen, dest.x, dest.y, dest.w, dest.h);

	/*Set up Pieces for White side Row 2 of the chess board*/
	dest.y = Row2;
	for(x=0; x<8; x++)  /*use for loop since all column are Pawns	*/
	{
		image = SDL_DisplayFormat(PiecePawnWhite);
		dest.x = x*image->w;
		SDL_BlitSurface(image, &src, screen, &dest);
		SDL_UpdateRect(screen, dest.x, dest.y, dest.w, dest.h);
	}




	/*Release the surface*/
	SDL_FreeSurface(image);

	SDL_FreeSurface(PieceKingWhite);
	SDL_FreeSurface(PieceQueenWhite);
	SDL_FreeSurface(PieceRookWhite);
	SDL_FreeSurface(PieceBishopWhite);
	SDL_FreeSurface(PieceKnightWhite);
	SDL_FreeSurface(PiecePawnWhite);

	SDL_FreeSurface(PieceKingBlack);
	SDL_FreeSurface(PieceQueenBlack);
	SDL_FreeSurface(PieceRookBlack);
	SDL_FreeSurface(PieceBishopBlack);
	SDL_FreeSurface(PieceKnightBlack);
	SDL_FreeSurface(PiecePawnBlack);

	SDL_FreeSurface(BoardWhite);
	SDL_FreeSurface(BoardBlack);

	/*Return success!*/
	SDL_Quit();
}
