#include "print_with_sdl.h"

    // const int SCREEN_WIDTH = WIDTH_OF_BOARD*10;
    // const int SCREEN_HEIGHT = HEIGHT_OF_BOARD*10;
/**
 * @brief 
 * @param renderer
 * @param Board
 * 
 * @return 
 * 
 */

 void draw(SDL_Renderer* renderer,struct board Board)
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, 255,255,255,255);
	for(int i=0; i<HEIGHT_OF_BOARD; ++i)
	{
		for(int j= 0; j<WIDTH_OF_BOARD; ++j)
			if (Board.cells[i][j] == ALIVE_CELL){
				SDL_Rect rect = {j*10, i*10, 10, 10};
				//SDL_RenderDrawPoint(renderer,j,i);
				SDL_RenderDrawRect( renderer, &rect );
				}
	}

	// MOUSE INTERACTION
	int x,y;
	if ( SDL_GetMouseState(&x,&y) & SDL_BUTTON(SDL_BUTTON_LEFT) ) // one & it is for bits AND
	{
		// USE COLOR
		SDL_SetRenderDrawColor(renderer, 255,0,0,0);
		SDL_RenderDrawPoint(renderer,x,y);
	}
}
