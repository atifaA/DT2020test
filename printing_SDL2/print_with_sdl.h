#ifndef PRINT_TO_SDL_H
#define PRINT_TO_SDL_H

#include "../game/game.h"
#include <stdlib.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <stdint.h>
#include <time.h>

#include <SDL2/SDL.h> 


    // int print_SDL_init();

   // int print_SDL_print(struct board Board);
    void draw(SDL_Renderer* renderer,struct board Board);


    // void print_SDL_close();

#endif