#include "game.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


#define HEIGHT_OF_BOARD 50
    #define WIDTH_OF_BOARD 50
    #define DEAD_CELL 0
    #define ALIVE_CELL 1
    #define CIRCULAR_BOARD 1
    #define CLIPPED_BOARD 0

    #define DEBUG_TRUE 1
    #define DEBUG_FALSE 0

    // struct cell{
    //     int x;
    //     int y;
    //     unsigned int dead;
    // };

    struct board{
        unsigned short cells[WIDTH_OF_BOARD][HEIGHT_OF_BOARD];
        unsigned short circular_flag;
    };


    void new_random_board(struct board *brd, unsigned short circular_flag);

    int clipped_neighbours(struct board brd, int x, int y);
    int circular_neighbour(struct board brd, int x, int y);
    struct board new_board(struct board brd);
    void print_board(struct board brd, unsigned short debug);




void new_random_board(struct board *brd, unsigned short circular_flag){
    time_t t;
    
    srand((unsigned) time(&t));

    brd->circular_flag = circular_flag;

    for (int i = 0; i < HEIGHT_OF_BOARD; i++)
    {
        for (int j = 0; j < WIDTH_OF_BOARD; j++){
            
            if (rand()%10 > 7){
                brd->cells[i][j] = ALIVE_CELL;
            }else{
                brd->cells[i][j] = DEAD_CELL;
            }
        }
    }
}

struct board new_board(struct board brd){
    struct board new_board;
    new_board.circular_flag = brd.circular_flag;
    for (int i = 0; i< HEIGHT_OF_BOARD; i++){
        for (int j = 0; j < WIDTH_OF_BOARD; j++){
            int nghbrs = 0;
            if (brd.circular_flag == CLIPPED_BOARD){
                nghbrs = clipped_neighbours(brd, j, i);
            }else{
                nghbrs = circular_neighbour(brd, j, i);
            }


            if (brd.cells[i][j] == ALIVE_CELL){
                if (nghbrs == 2 || nghbrs == 3){
                    new_board.cells[i][j] = ALIVE_CELL;
                }else{
                    new_board.cells[i][j] = DEAD_CELL;
                }
            }else{
                if (nghbrs == 3){
                    new_board.cells[i][j] = ALIVE_CELL;
                }else{
                    new_board.cells[i][j] = DEAD_CELL;
                }
            }
        }
    }

    return new_board;
}

void print_board(struct board brd, unsigned short debug){

    printf("\e[2J");
    printf("\e[0;0H");
    
    for (int i = 0; i < HEIGHT_OF_BOARD; i++)
    {
        for (int j = 0; j < WIDTH_OF_BOARD; j++)
        {
            if(debug == DEBUG_FALSE)
                printf((brd.cells[i][j] == ALIVE_CELL ? "\033[07m  \e[0m" : "  "));
            else
                // printf( (brd.cells[i][j] == ALIVE_CELL ? "\033[07m%d \e[0m" : "%d "),
                //     (brd.circular_flag == CLIPPED_BOARD ? clipped_neighbours(brd, j, i) : circular_neighbour(brd, j, i)) );
        }
        printf("\n");
        
    }
