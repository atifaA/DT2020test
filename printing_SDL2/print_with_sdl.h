#ifndef PRINT_WITH_SDL_H
#define PRINT_WITH_SDL_H

#include "../game/game.h"

#include <SDL2/SDL.h> 


    int withSDL_init(int Board_width, int Board_height);

    int withSDL_print(struct board Board);

    void withSDL_close();

#endif