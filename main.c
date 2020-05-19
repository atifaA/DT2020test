#include <stdio.h>
#include <unistd.h>
#include "game/game.h"
#include "console/print_with_ansi.h"
#include "printing_SDL2/print_with_sdl.h"
#include <getopt.h>
#include <signal.h>


int quit = 0;

void quit_signal(){
    quit = 1;
}


int main(int argc, char const *argv[])
{
    struct board Board;
    user_init_param(&Board, 500, 50, CIRCULAR_BOARD);
    create_random_board(&Board);
    BoardPrinting_ansi(Board, FALSE);
    // print_SDL_print(Board);
    //SDL_Event e;
    signal(SIGINT, quit_signal);

    while(!quit){
        sleep(1);
        Board = create_new_board(Board);
        BoardPrinting_ansi(Board, FALSE);
        // print_SDL_print(Board);
        // while (SDL_PollEvent(&e)){
            // if(e.type == SDL_QUIT){
            //     quit = 1;
            // }
        //}

    }

    //print_SDL_close();
    destroy_board(&Board);

    return 0;
}


// #include <unistd.h>
// #include <SDL2/SDL.h>
// #include <signal.h>
// #include "game.h"

// int quit = 0;

// void quit_signal(){
//     quit = 1;
// }
// int main(int argc, char const *argv[])
// {
//     struct board brd;
//     init_board(&brd, 60, 50, CIRCULAR_BOARD);
//     new_random_board(&brd);
//     print_board(brd, DEBUG_FALSE);
//     // print_SDL_init();
//     // print_SDL_print(brd);

//     // SDL_Event e;
//     signal(SIGINT, quit_signal);

//     while(!quit){
//         sleep(1);
//         brd = next_board(brd);
//         print_board(brd, DEBUG_FALSE);
//         // print_SDL_print(brd);
//         // while (SDL_PollEvent(&e)){
//         //     if (e.type == SDL_QUIT){
//         //         quit = 1;
//         //     }
//         // }
//     }
    
//     // print_SDL_close();

//     destroy_board(&brd);



//     return 0;
// }