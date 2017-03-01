/***********************************
*
*
* FinalDisplayBoard.c
*	1/27/13 Initial Creation: Namirud Yegezu
*
*
*
*
*
*
************************************/

#include<SDL/SDL.h>
#include<stdio.h>
#include<stdlib.h>

int main()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Surface* screen;
	screen = SDL_SetVideoMode(640,480,32,SDL_SWSURFACE);
	char false;
	char true;
	char running;
	running = true;
	while(running)
	{
		SDL_Event event;
		while(SDL_PollEvent(&event))
		{
			switch(event.type)
			{
				case SDL_QUIT:
					running = false;
					breaak;
			}

		}
		/* logic and render */
		SDL_Flip(screen);
	}
	SDL_Quit();
	return 0;
}
