#include "game.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int clipped_neighbours(struct board Board, int x,int y){

    int counter_neighbours=0;

    for(int i = -1; i <= 1; i++)
    {
        for(int j = -1; j <= 1; j++)
        {
            if ( !(y+i<0 || x+j<0 || y+i >= HEIGHT_OF_BOARD || x+j >= WIDTH_OF_BOARD) ){
                if(Board.cells[y+i][x+j] == ALIVE_CELL)
                {
                    if(!(i == 0 && j == 0)){
                        counter_neighbours++;
                    }
                
                }
            }
        }

    }
    return counter_neighbours;

}

int circular_neighbour(struct board Board, int x, int y){
    int counter_neighbours=0;

    for(int i = -1; i <= 1; i++)
    {
        for(int j = -1; j <= 1; j++)
        {
            
            int y_temp = y+i;
            int x_temp = x+j;

            if (y+i<0)
                y_temp = HEIGHT_OF_BOARD - 1;
            if (x+j<0)
                x_temp = WIDTH_OF_BOARD - 1;
            if (y+i >= HEIGHT_OF_BOARD)
                y_temp = 0;
            if (x+j >= WIDTH_OF_BOARD)
                x_temp = 0;

            if(Board.cells[y_temp][x_temp] == ALIVE_CELL)
            {
                if(!(i == 0 && j == 0)){
                    counter_neighbours++;
                }
            
            }
        }

    }
    return counter_neighbours;
}


void create_random_board(struct board *Board, unsigned short circular_flag){
    time_t t;
    
    srand((unsigned) time(&t));

    Board->circular_flag = circular_flag;

    for (int i = 0; i < HEIGHT_OF_BOARD; i++)
    {
        for (int j = 0; j < WIDTH_OF_BOARD; j++){
            
            if (rand()%10 > 7){
                Board->cells[i][j] = ALIVE_CELL;
            }else{
                Board->cells[i][j] = DEAD_CELL;
            }
        }
    }
}

struct board create_new_board(struct board Board){
    struct board new_board;
    new_board.circular_flag = Board.circular_flag;
    for (int i = 0; i< HEIGHT_OF_BOARD; i++){
        for (int j = 0; j < WIDTH_OF_BOARD; j++){
            int nghbrs = 0;
            if (Board.circular_flag == CLIPPED_BOARD){
                nghbrs = clipped_neighbours(Board, j, i);
            }else{
                nghbrs = circular_neighbour(Board, j, i);
            }


            if (Board.cells[i][j] == ALIVE_CELL){
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