#include <stdio.h>
#include <unistd.h>
#include "game.h"
#include "print_with_ansi.h"

int main(int argc, char const *argv[])
{
    struct board Board;
    create_random_board(&Board, CIRCULAR_BOARD);
    BoardPrinting_ansi(Board, FALSE);

    while(1){
        sleep(1);
        Board = create_new_board(Board);
        BoardPrinting_ansi(Board, FALSE);
    }

    return 0;
}