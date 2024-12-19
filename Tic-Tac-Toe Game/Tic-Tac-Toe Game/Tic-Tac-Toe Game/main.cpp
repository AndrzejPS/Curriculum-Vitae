#include "Functions.h"
#include "Board.h"
#include "Players.h"
#include "Game_rules.h"
#include <iostream>

int main()
{
    std::map<int, std::string> menu =
    {
        {1, "New game"},
        {2, "High score table"},
        {3, "Game information"},
        {4, "Exit game" }
    };

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
            if (check_game_results(p1, board, board_size)) break;

            //Bot's turn
            AI_turn(board, board_size,p2);
            write_board(board, board_size);
            if (check_game_results(p2, board, board_size)) break;
        }

        switch (rematch())
        {
        case 'N': return 0;
        case 'Y':break;
        default: std::cerr << "Error: code(1)!"; return(1);
        }
        clear_board(board);
    }
}

/*
To do list:
1. Walidacje!
2. Menu
3. Scoring
*/