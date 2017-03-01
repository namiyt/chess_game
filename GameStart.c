/************************************************
*												*
*												*
*	Team 5										*
*	1/28/14 Initial Creation					*
*		GameStart.c by Namirud Yegezu			*
*												*
*												*
*												*
*												*
* 	GUI for the chess game(using SDL)			*
*												*
************************************************/

#include <stdio.h>
#include <SDL/SDL.h>
#include <stdlib.h>
#include "../Buttons"

#define EVENTS

int SDL_ChooseColor(void);

int main(void)
{
	SDL_Surface *window;
	SDL_Surface *image;
	SDL_Surface *PvP_button, *PvA_button, *AvA_button, *Quit_button, *Logfile_button;
	int chosen;

#ifdef EVENTS
	SDL_Event event;
	int Running;
	int x;
	int y;
#endif

	/*We must first initialize the SDL video component, and check for success*/
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		printf("Unable to initialize SDL: %s\n", SDL_GetError());
		return 1;
	}

	atexit(SDL_Quit);
	/* Set the video mode to a window of size 1024 by 768 pixels with 32 bits per pixel */
	window = SDL_SetVideoMode(1024,768,32, SDL_ANYFORMAT);
	if (window == NULL)
	{
		printf("Unable to set video mode: %s\n", SDL_GetError());
		return 1;
	}

	/*Set the title bar*/
	SDL_WM_SetCaption("Team V: Chess Game",0);

	/*Load the title and buttom image and check for success*/
	PvP_button = SDL_LoadBMP("pvpbutton.bmp");
	if(PvP_button == NULL)
	{
		printf("Unable to load bitmap: %s\n", SDL_GetError());
		return 1;
	}

	PvA_button = SDL_LoadBMP("pvabutton.bmp");
	if(PvA_button == NULL)
	{
		printf("Unable to load bitmap: %s\n", SDL_GetError());
		return 1;
	}
	
	AvA_button = SDL_LoadBMP("avabutton.bmp");
	if(AvA_button == NULL)
	{
		printf("Unable to load bitmap: %s\n", SDL_GetError());
		return 1;
	}

	Quit_button = SDL_LoadBMP("quitbutton.bmp");
	if(Quit_button == NULL)
	{
		printf("Unable to load bitmap: %s\n", SDL_GetError());
		return 1;
	}

	image = SDL_LoadBMP("Team5.bmp");
	if(image == NULL)
	{
		printf("Unable to load bitmap: %s\n", SDL_GetError());
		return 1;
	}
	Logfile_button = SDL_LoadBMP("logfilebutton.bmp");
	if(Logfile_button == NULL)
	{
		printf("Unable to load bitmap: %s\n", SDL_GetError());
		return 1;
	}


	SDL_Rect rect_pvp, rect_pva, rect_ava, rect_quit, rect_image, rect_logfile;
	rect_pvp.x = 747;
	rect_pvp.y = 411;
	rect_pva.x = 747;
	rect_pva.y = 482;
	rect_ava.x = 747;
	rect_ava.y = 553;
	rect_quit.x = 747;
	rect_quit.y = 645;
	rect_image.x = 0;
	rect_image.y = 0;
	rect_logfile.x = 100;
	rect_logfile.y = 645;


	/*Apple the image to the window*/
	SDL_BlitSurface(PvP_button, NULL, window, &rect_pvp);
	SDL_BlitSurface(PvA_button, NULL, window, &rect_pva);
	SDL_BlitSurface(AvA_button, NULL, window, &rect_ava);
	SDL_BlitSurface(Quit_button, NULL, window, &rect_quit);
	SDL_BlitSurface(Logfile_button, NULL, window, &rect_logfile);

	if (SDL_BlitSurface(image, NULL, window, &rect_image) != 0)
	{
		printf("Unable to display image: %s\n", SDL_GetError());
		exit(1);
	}
	if (SDL_BlitSurface(PvP_button, NULL, window, &rect_pvp) != 0)
	{
		printf("Unable to display image: %s\n", SDL_GetError());
		exit(1);
	}
	if (SDL_BlitSurface(PvA_button, NULL, window, &rect_pva) != 0)
	{
		printf("Unable to display image: %s\n", SDL_GetError());
		exit(1);
	}
	if (SDL_BlitSurface(AvA_button, NULL, window, &rect_ava) != 0)
	{
		printf("Unable to display image: %s\n", SDL_GetError());
		exit(1);
	}
	if (SDL_BlitSurface(Quit_button, NULL, window, &rect_quit) != 0)
	{
		printf("Unable to display image: %s\n", SDL_GetError());
		exit(1);
	}
	if (SDL_BlitSurface(Logfile_button, NULL, window, &rect_logfile) != 0)
	{
		printf("Unable to display image: %s\n", SDL_GetError());
		exit(1);
	}

	/*Update the display*/
	SDL_Flip(window);

	SDL_Delay(5000);

#ifdef EVENTS
	Running = 1;
	printf("Running!\n");
	while(Running && SDL_WaitEvent(&event))
	{
		printf("Received event.type = %d\n", event.type);
		switch(event.type)
		{ /* Process the appropriate event type */
			case SDL_KEYDOWN:  /* Handle a KEYDOWN event */
			{	
				printf("Oh! Key pressed!\n");
				break;
			}

			case SDL_MOUSEMOTION:
			/*{
				x = event.motion.x;
				y = event.motion.y;
				if((x>rect_pvp.x)&&(x<rect_pvp.x+205)&&(y>rect_pvp.y)&&(y<rect_pvp.y+40))
				{
					SDL_SetColorKey(PvP_button, SDL_SRCCOLORKEY, SDL_MapRGB(window->format,0,0,255));
					SDL_UpdateRect(window, rect_pvp.x, rect_pvp.y, 205, 40);
				}
				if((x>rect_pva.x)&&(x<rect_pva.x+205)&&(y>rect_pva.y)&&(y<rect_pva.y+40))
				{
					SDL_SetColorKey(PvA_button, SDL_SRCCOLORKEY, SDL_MapRGB(window->format,0,0,255));
					SDL_UpdateRect(window, rect_pva.x, rect_pva.y, 205, 40);
				}
				if((x>rect_ava.x)&&(x<rect_ava.x+205)&&(y>rect_ava.y)&&(y<rect_ava.y+40))
				{
					SDL_SetColorKey(AvA_button, SDL_SRCCOLORKEY, SDL_MapRGB(window->format,0,0,255));
					SDL_UpdateRect(window, rect_ava.x, rect_ava.y, 205, 40);
				}
				if((x>rect_quit.x)&&(x<rect_quit.x+205)&&(y>rect_quit.y)&&(y<rect_quit.y+40))
				{
					SDL_SetColorKey(Quit_button, SDL_SRCCOLORKEY, SDL_MapRGB(window->format,0,0,255));
					SDL_UpdateRect(window, rect_quit.x, rect_quit.y, 205, 40);
				}

				break;
			}*/
			case SDL_MOUSEBUTTONDOWN:
			{	
				printf("Mouse button %d pressed.\n", event.button.button);
				printf("Position is x=%d, y=%d.\n", event.button.x, event.button.y);
				x = event.button.x;
				y = event.button.y;
				if((x>rect_pvp.x)&&(x<rect_pvp.x+205)&&(y>rect_pvp.y)&&(y<rect_pvp.y+40)&&(event.button.button==SDL_BUTTON_LEFT))
				{
					chosen = 2; /*Calls to play human vs human*/
					SDL_FillRect(window, NULL, 0xffff);
					SDL_ChooseColor();
				}
				if((x>rect_pva.x)&&(x<rect_pva.x+205)&&(y>rect_pva.y)&&(y<rect_pva.y+40)&&(event.button.button==SDL_BUTTON_LEFT))
				{
					chosen = 1; /*Calls to play human vs ai*/
					SDL_FillRect(window, NULL, 0xffff);
					SDL_ChooseColor();
				}
				if((x>rect_ava.x)&&(x<rect_ava.x+205)&&(y>rect_ava.y)&&(y<rect_ava.y+40)&&(event.button.button==SDL_BUTTON_LEFT))
				{
					chosen = 3; /*Calls to play ai vs ai*/
				}
				if((x>rect_quit.x)&&(x<rect_quit.x+205)&&(y>rect_quit.y)&&(y<rect_quit.y+40)&&(event.button.button==SDL_BUTTON_LEFT))
				{
					Running = 0;
					break;
				}
				if((x>rect_logfile.x)&&(x<rect_logfile.x+205)&&(y>rect_logfile.y)&&(y<rect_logfile.y+40)&&(event.button.button==SDL_BUTTON_LEFT))
				{
					Readlog();
				}

			

			/*	SDL_BlitSurface(PvP_button, NULL, window, &rect_pvp);
				SDL_UpdateRect(window, rect_pvp.x, rect_pvp.y, 205, 40);
				SDL_BlitSurface(PvA_button, NULL, window, &rect_pva);
				SDL_UpdateRect(window, rect_pvp.x, rect_pvp.y, 205, 40);
				SDL_BlitSurface(AvA_button, NULL, window, &rect_ava);
				SDL_UpdateRect(window, rect_pvp.x, rect_pvp.y, 205, 40);
				SDL_BlitSurface(Back_button, NULL, window, &rect_back);
				SDL_UpdateRect(window, rect_pvp.x, rect_pvp.y, 205, 40);
				SDL_BlitSurface(Quit_button, NULL, window, &rect_quit);
				SDL_UpdateRect(window, rect_pvp.x, rect_pvp.y, 205, 40);*/

				break;
			}
			case SDL_QUIT:
			{	
				printf("Quit event received!\n");
				Running = 0;
				break;
			}
			default: /* ignore any other events */
			{	
				printf("Oops, unknown event!\n");
				break;
			}
		} /* hctiws */
		if((chosen == 1) || (chosen == 2) || (chosen == 3))
		{
			break;
		}

	} /* elihw */
#endif


	

	SDL_FreeSurface(PvP_button);
	SDL_FreeSurface(PvA_button);
	SDL_FreeSurface(AvA_button);
	SDL_FreeSurface(Quit_button);
	SDL_FreeSurface(image);

	return chosen;

}

int SDL_ChooseColor(void)
{
	SDL_Surface *window, *image;
	SDL_Surface *Black_button, *White_button;
	int colorchosen

	#ifdef EVENTS
	SDL_Event event;
	int Running;
	int x;
	int y;
	#endif

	/*We must first initialize the SDL video component, and check for success*/
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		printf("Unable to initialize SDL: %s\n", SDL_GetError());
		return 1;
	}

	atexit(SDL_Quit);
	/* Set the video mode to a window of size 1024 by 768 pixels with 32 bits per pixel */
	window = SDL_SetVideoMode(1024,768,32, SDL_ANYFORMAT);

	Black_button = SDL_LoadBMP("blackbutton.bmp");
	if(Black_button == NULL)
	{
		printf("Unable to load bitmap: %s\n", SDL_GetError());
		return 1;
	}
	White_button = SDL_LoadBMP("whitebutton.bmp");
	if(White_button == NULL)
	{
		printf("Unable to load bitmap: %s\n", SDL_GetError());
		return 1;
	}
	image = SDL_LoadBMP("Team5.bmp");
	if(image == NULL)
	{
		printf("Unable to load bitmap: %s\n", SDL_GetError());
		return 1;
	}

	SDL_Rect rect_black, rect_white, rect_image;
	rect_black.x = 512;
	rect_black.y = 344;
	rect_white.x = 512;
	rect_white.y = 404;
	rect_image.x = 0;
	rect_image.y = 0;

	SDL_BlitSurface(Black_button, NULL, window, &rect_black);
	SDL_BlitSurface(White_button, NULL, window, &rect_white);

	if (SDL_BlitSurface(Black_button, NULL, window, &rect_black) != 0)
	{
		printf("Unable to display image: %s\n", SDL_GetError());
		exit(1);
	}
	if (SDL_BlitSurface(White_button, NULL, window, &rect_white) != 0)
	{
		printf("Unable to display image: %s\n", SDL_GetError());
		exit(1);
	}

	SDL_Flip(window);

#ifdef EVENTS
	Running = 1;
	printf("Running!\n");
	while(Running && SDL_WaitEvent(&event))
	{
		printf("Received event.type = %d\n", event.type);
		switch(event.type)
		{ /* Process the appropriate event type */
			case SDL_KEYDOWN:  /* Handle a KEYDOWN event */
			{	
				printf("Oh! Key pressed!\n");
				break;
			}

			case SDL_MOUSEBUTTONDOWN:
			{	
				printf("Mouse button %d pressed.\n", event.button.button);
				printf("Position is x=%d, y=%d.\n", event.button.x, event.button.y);
				x = event.button.x;
				y = event.button.y;
				if((x>rect_black.x)&&(x<rect_black.x+205)&&(y>rect_black.y)&&(y<rect_black.y+40)&&(event.button.button==SDL_BUTTON_LEFT))
				{
					printf("hello\n");
					colorchosen = 1; /*chooses to be black*/
				}
				if((x>rect_white.x)&&(x<rect_white.x+205)&&(y>rect_white.y)&&(y<rect_white.y+40)&&(event.button.button==SDL_BUTTON_LEFT))
				{
					printf("hell5o\n");
					colorchosen = 2; /*chooses to be white*/
				}

				break;
			}
			case SDL_QUIT:
			{	
				printf("Quit event received!\n");
				Running = 0;
				break;
			}
			default: /* ignore any other events */
			{	
				printf("Oops, unknown event!\n");
				break;
			}
		} /* hctiws */
		if((colorchosen == 1) || (colorchosen == 2))
		{
			break;
		}

	} /* elihw */
#endif

	SDL_FreeSurface(Black_button);
	SDL_FreeSurface(White_button);
	SDL_FreeSurface(image);

	return colorchosen;
}


