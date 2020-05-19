
#ifndef GAME_H
#define GAME_H

     #define HEIGHT_OF_BOARD 40
     #define WIDTH_OF_BOARD 40

    #define DEAD_CELL 0
    #define ALIVE_CELL 1
    #define CIRCULAR_BOARD 1
    #define CLIPPED_BOARD 0



    struct board{
        // unsigned short cells[WIDTH_OF_BOARD][HEIGHT_OF_BOARD];
        // unsigned short circular_flag;
        unsigned short **cells; 
        unsigned short type_flag;
        int height;
        int width; 

    };

//new random
    void create_random_board(struct board *Board);

    int clipped_neighbours(struct board Board, int x, int y);
    int circular_neighbour(struct board Board, int x, int y);
    struct board create_new_board(struct board Board);  //next board
    void user_init_param(struct board *Board, int width, int height, unsigned short type_flag);
    void destroy_board(struct board *Board);
#endif
