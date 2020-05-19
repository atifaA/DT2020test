#include "game.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
/**
 * Non-Circular Neighbours
 * @brief 
 * @param Board 
 * @param x
 * @param y
 * @return int
 */

int clipped_neighbours(struct board Board, int x,int y){

    int counter_neighbours=0;

    for(int i = -1; i <= 1; i++){
        for(int j = -1; j <= 1; j++){
            if ( !(y+i<0 || x+j<0 || y+i >= Board.height || x+j >= Board.width) ){
                if(Board.cells[y+i][x+j] == ALIVE_CELL){
                    if(!(i == 0 && j == 0)){
                        counter_neighbours++;
                    }               
                }
            }
        }
    }
    return counter_neighbours;

}
/** Circular Neighbours
 * @brief 
 * @param Board 
 * @param x
 * @param y
 * @return int
 */

int circular_neighbour(struct board Board, int x, int y){
    int counter_neighbours=0;

    for(int i = -1; i <= 1; i++)
    {
        for(int j = -1; j <= 1; j++)
        {
            
            int y_temp = y+i;
            int x_temp = x+j;

            if (y+i<0)
                y_temp = Board.height - 1;
            if (x+j<0)
                x_temp = Board.width - 1;
            if (y+i >= Board.height)
                y_temp = 0;
            if (x+j >= Board.width)
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
/**
 * Create Random Board
 * DEAD_CELL or ALIVE_CELL are randomly assigned on the existing cells.
 * @brief 
 * @param Board 
 * @param circular_flag ineger
 * @return int
 */

void create_random_board(struct board *Board){
    time_t t;
    srand((unsigned) time(&t));

    // Board->type_flag = type_flag;

    for (int i = 0; i < Board->height; i++)
    {
        for (int j = 0; j < Board->width; j++){            
            if (rand()%10 > 7){
                Board->cells[i][j] = ALIVE_CELL;
            }else{
                Board->cells[i][j] = DEAD_CELL;
            }
        }
    }
}
/**
 * Creates a new board from board using specified rules based on neighbours
 * @brief 
 * @param Board 
 * @return struct board
 */
struct board create_new_board(struct board Board){
    struct board new_board;
    user_init_param(&new_board, Board.width, Board.height, Board.type_flag);
    new_board.type_flag = Board.type_flag;
    for (int i = 0; i< Board.height; i++){
        for (int j = 0; j < Board.width; j++){
            int neighbours = 0;
            if (Board.type_flag == CLIPPED_BOARD){
                neighbours = clipped_neighbours(Board, j, i);
            }else{
                neighbours = circular_neighbour(Board, j, i);
            }
            if (Board.cells[i][j] == ALIVE_CELL){
                if (neighbours == 2 || neighbours == 3){
                    new_board.cells[i][j] = ALIVE_CELL;
                }else{
                    new_board.cells[i][j] = DEAD_CELL;
                }
            }else{
                if (neighbours == 3){
                    new_board.cells[i][j] = ALIVE_CELL;
                }else{
                    new_board.cells[i][j] = DEAD_CELL;
                }
            }
        }
    }

    return new_board;
}


void user_init_param(struct board *Board, int width, int height, unsigned short type_flag){
    Board->type_flag = type_flag;
    Board->height = height;
    Board->width = width;
    Board->cells = malloc(Board->height * sizeof(unsigned short *));
    for(int i = 0; i < Board->height; i++){
        Board->cells[i] = malloc(Board->width * sizeof(unsigned short));
    }
}


void destroy_board(struct board *Board){


    for (int i = 0; i < Board->height; i++){
        free(Board->cells[i]);
    }
    free(Board->cells);
}
