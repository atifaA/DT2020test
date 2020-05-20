#include "print_with_sdl.h"

    // const int SCREEN_WIDTH = WIDTH_OF_BOARD*10;
    // const int SCREEN_HEIGHT = HEIGHT_OF_BOARD*10;
    // // The window 
//     SDL_Window* window = NULL;
    
//     //The surface contained by the window
//     SDL_Surface* screenSurface = NULL;

// //initializing the GUI
// int withSDL_init(int Board_width , int Board_height){
//     int res = 0;
//     const int SCREEN_WIDTH = Board_width*10;
//     const int SCREEN_HEIGHT = Board_height*10;
//     if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_EVENTS ) < 0 ){
//         printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
//         res = 1;
//     }else{
//         window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
//         if( window == NULL ){
//             printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
//             res = 1;
//         }else{
//             screenSurface = SDL_GetWindowSurface( window );
//         }
//     }
//     return res;
// }
// //showing board on the GUI 
// int withSDL_print(struct board Board){
//     SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0x00, 0x00, 0x00 ) );
//     for (int i = 0; i < Board.height; i++){
//         for (int j = 0; j < Board.width; j++){
//             // printf((Board.cells[i][j] == ALIVE_CELL ? "\033[07m  \e[0m" : "  "));
//             if (Board.cells[i][j] == ALIVE_CELL){
//                 const SDL_Rect rectangle = {j*10, i*10, 10, 10};
//                 SDL_FillRect(screenSurface, &rectangle, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ));
//             }
//         }
//         printf("\n");    
//     }
//     SDL_UpdateWindowSurface( window );
// }

// //Quiting the GUI
// void withSDL_close(){
//     SDL_FreeSurface(screenSurface);
//     screenSurface = NULL;
//     SDL_DestroyWindow(window);
//     window = NULL;
//     SDL_Quit();
// }



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
