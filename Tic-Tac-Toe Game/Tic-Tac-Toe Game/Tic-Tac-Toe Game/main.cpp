#include <iostream>
#include "Functions.h"

int main()
{
    const int board_size = 3;
    std::vector<std::vector<char>> board = create_board(board_size);

    while (true)
    {
        write_board(board, board_size);
        players_turn(board, board_size);
        write_board(board, board_size);
        if(win_condition(board, board_size)) break;
        AI_turn(board, board_size);
        write_board(board, board_size);
        if (win_condition(board, board_size)) break;
    }
   
}

