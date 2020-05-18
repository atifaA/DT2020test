#ifndef PRINT_TO_SDL_H
#define PRINT_TO_SDL_H

#include "../game/game.h"

#include <SDL2/SDL.h> 


    int print_SDL_init();

    int print_SDL_print(struct board Board);

    void print_SDL_close();

#endif