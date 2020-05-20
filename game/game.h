#ifndef GAME_H
#define GAME_H

    #define HEIGHT_OF_BOARD 40
    #define WIDTH_OF_BOARD 40
    #define DEAD_CELL 0
    #define ALIVE_CELL 1
    #define CIRCULAR_BOARD 1
    #define CLIPPED_BOARD 0



    struct board{
        unsigned short cells[WIDTH_OF_BOARD][HEIGHT_OF_BOARD];
        unsigned short circular_flag;
    };

//new random
    void create_random_board(struct board *Board, unsigned short circular_flag);

    int clipped_neighbours(struct board Board, int x, int y);
    int circular_neighbour(struct board Board, int x, int y);
    struct board create_new_board(struct board Board);  //next board

#endif