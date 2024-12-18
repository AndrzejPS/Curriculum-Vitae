#include <iostream>
#include "Functions.h"
#include "Board.h"
#include "Players.h"

int main()
{
    std::map<int, char> symbols;
    symbols[1] = 'X';
    symbols[2] = 'O';
    symbols[3] = 'Y';
    //to add an emblem, just type a new one here

    profile p1 = { "Andrzej" };
    profile p2 = { "Bot" };

   

    while (true)
    {
        const int board_size = choose_board_size();
        std::vector<std::vector<char>> board = create_board(board_size);
        random_emblem_for_bot(p2, symbols, emblem_choice(symbols, p1));
        while (true)
        {
            //player's turn
            write_board(board, board_size);
            players_turn(board, board_size,p1);
            write_board(board, board_size);
            if (win_conditions(board, board_size, p1))
            {
                std::cout << "The winner is " << p1.profile_name << "!";
                freeze_screen();
                break;
            }
            else if (!free_spaces(board))
            {
                std::cout << "It's a tie!";
                freeze_screen();
                break;
            }

            //Bot's turn
            AI_turn(board, board_size,p2);
            write_board(board, board_size);
            if (win_conditions(board, board_size, p2))
            {
                std::cout << "The winner is " << p2.profile_name << "!";
                freeze_screen();
                break;
            }
            else if (!free_spaces(board))
            {
                std::cout << "It's a tie!";
                freeze_screen();
                break;
            }
        }

        switch (rematch())
        {
        case 'N': return 0;
        case 'Y':;
        }
        clear_board(board);
    }
}

