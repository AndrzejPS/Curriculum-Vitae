#include "Functions.h"
#include "Board.h"
#include "Players.h"
#include "Game_rules.h"
#include <iostream>

int main()
{
    std::map<int, char> symbols;
    symbols[1] = 'X';
    symbols[2] = 'O';
    symbols[3] = 'Y';
    //to add an emblem, just type a new one here

    profile p1,p2;

    int gamemode = menu(p1, p2, symbols);
   
    while (true)
    {
        const int board_size = choose_board_size();
        std::vector<std::vector<char>> board = create_board(board_size);

        switch (gamemode)
        {
            case 1:
            {
                while (true)
                {
                    //player's turn
                    write_board(board, board_size);
                    players_turn(board, board_size, p1);
                    write_board(board, board_size);
                    if (check_game_results(p1, board, board_size)) break;

                    //Bot's turn
                    AI_turn(board, board_size, p2);
                    write_board(board, board_size);
                    if (check_game_results(p2, board, board_size)) break;
                }
                break;
            }
           
            case 2:
            {
                while (true)
                {
                    //player1's turn
                    write_board(board, board_size);
                    players_turn(board, board_size, p1);
                    write_board(board, board_size);
                    if (check_game_results(p1, board, board_size)) break;

                    //Player2's turn
                    players_turn(board, board_size, p2);
                    write_board(board, board_size);
                    if (check_game_results(p2, board, board_size)) break;
                }
            }
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
1. Validation!
2. Menu
3. Scoring
*/