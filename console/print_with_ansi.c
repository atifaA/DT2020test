#include <stdio.h>
#include "print_with_ansi.h"

void BoardPrinting_ansi(struct board Board, unsigned short FALSEorTRUE){

    printf("\e[2J");
    printf("\e[0;0H");
    
    for (int i = 0; i < HEIGHT_OF_BOARD; i++){
        for (int j = 0; j < WIDTH_OF_BOARD; j++){
            if(FALSEorTRUE == FALSE)
                printf((Board.cells[i][j] == ALIVE_CELL ? "\033[07m  \e[0m" : "  "));
            else
                printf( (Board.cells[i][j] == ALIVE_CELL ? "\033[07m%d \e[0m" : "%d "),
                    (Board.circular_flag == CLIPPED_BOARD ? clipped_neighbours(Board, j, i) : circular_neighbour(Board, j, i)) );
        }
        printf("\n");
        
    }
       
}