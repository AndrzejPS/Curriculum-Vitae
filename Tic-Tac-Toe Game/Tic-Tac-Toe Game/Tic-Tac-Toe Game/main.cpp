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
    symbols[4] = '!';
    symbols[5] = '?';
    //to add an emblem, just type a new one here

    profile p1,p2;

    while (true)
    {
        int choice = menu(p1, p2, symbols);
        if (choice == 5) break;

        while (true)
        {
           const int gamemode = gamemode_decision();
            const int board_size = choose_board_size();
            std::vector<std::vector<char>> board = create_board(board_size);

            switch (choice)
            {
                case 1:
                {
                    while (true)
                    {
                        //player's turn
                        write_board(board, board_size);
                        players_turn(board, board_size, p1);
                        write_board(board, board_size);
                        if (check_game_results(p1, p2, board, board_size))
                        {
                            save_score_decision(make_leaderboard(), p1);
                            break;
                        }
                        if (gamemode == 2) crazy_mode(board, board_size);

                        //Bot's turn
                        AI_turn(board, board_size, p2);
                        write_board(board, board_size);
                        if (check_game_results(p2,p1, board, board_size)) break;
                        if (gamemode == 2) crazy_mode(board, board_size);
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
                        if (check_game_results(p1, p2, board, board_size))
                        {
                            save_score_decision(make_leaderboard(), p1);
                            break;
                        }
                        if (gamemode == 2) crazy_mode(board, board_size);

                        //Player2's turn
                        players_turn(board, board_size, p2);
                        write_board(board, board_size);
                        if (check_game_results(p2, p1, board, board_size))
                        {
                            save_score_decision(make_leaderboard(), p2);
                            break;
                        } 
                        if (gamemode == 2) crazy_mode(board, board_size);
                    }
                }
            }

            switch (rematch())
            {
            case 'N': break;
            case 'Y': clear_board(board); continue;
            default: std::cerr << "Error: code(1)!"; return(1);
            }

            break;
        }
    }
}

/*
To do list:
1. Validation!
*/