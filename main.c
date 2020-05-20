#include <stdio.h>
#include <unistd.h>
#include "game/game.h"
#include "console/print_with_ansi.h"
#include "printing_SDL2/print_with_sdl.h"
#include <signal.h>
#include <getopt.h>

int quit = 0;

void quit_signal()
{
	quit = 1;
}
int main(int argc, char const *argv[])
{
	struct board Board;
	create_random_board(&Board, CIRCULAR_BOARD);
	int n;
	printf("please enter 1 for ansi 2 for sdl\n");
	scanf("%d", &n);
	if (n == 1)
	{
		signal(SIGINT, quit_signal);
		BoardPrinting_ansi(Board, FALSE);
		while (!quit)
		{
			sleep(1);
			Board = create_new_board(Board);
			BoardPrinting_ansi(Board, FALSE);
		}
	}
	if (n == 2)
	{
		if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0)
		{
			fprintf(stderr, "Problem can not init SDL2 \n");
			return 0;
		}

		SDL_Window *window = SDL_CreateWindow("Life", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, HEIGHT_OF_BOARD * 10, WIDTH_OF_BOARD * 10, SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI);
		SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		assert(renderer != NULL);

		// SIMPLE EVENT & DRAWING LOOP
		bool quit = false;
		while (!quit)
		{
			SDL_Event event;
			while (!quit && SDL_PollEvent(&event))
			{
				switch (event.type)
				{
				case SDL_QUIT:
					quit = true;
					break;
				}
			}
			draw(renderer, Board);
			SDL_RenderPresent(renderer);
		}
		SDL_Quit();
	}

	return 0;
}