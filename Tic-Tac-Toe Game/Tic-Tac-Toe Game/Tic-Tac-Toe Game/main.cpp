#include <iostream>
#include "Functions.h"
#include <map>

int main()
{
    const int board_size = 3;
    std::vector<std::vector<char>> board = create_board(board_size);
    player p1 = { "Andrzej" };
    player p2 = { "Bot" };

    std::map<int, char> symbols;
    symbols[1] = 'X';
    symbols[2] = 'Y';
    symbols[3] = 'Z';
    symbols[4] = 'C';

    while (true)
    {
        write_menu(symbols,p1);

        while (true)
        {
            //player's turn
            write_board(board, board_size);
            players_turn(board, board_size,p1);
            write_board(board, board_size);
            if (win_conditions(board, board_size, p1))
            {
                std::cout << "The winner is " << p1.players_name << "!";
                std::cin.get();
                break;
            }
            else if (!free_spaces(board, board_size))
            {
                std::cout << "It's a tie!";
                break;
            }

            //Bot's turn
            AI_turn(board, board_size);
            write_board(board, board_size);
            if (win_conditions(board, board_size, p2))
            {
                std::cout << "The winner is " << p2.players_name << "!";
                std::cin.get();
                break;
            }
            else if (!free_spaces(board, board_size))
            {
                std::cout << "It's a tie!";
                std::cin.get();
                break;
            }
        }

        system("cls");
        std::cout << "Do you want to play once more?[Y/N]";
        char choice;
        std::cin >> choice;
        choice = toupper(choice);
        switch (choice)
        {
            case 'N': return 0;
            case 'Y':;
        }
    }
}

