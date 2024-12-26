#include "Board.h"
#include <iostream>

int choose_board_size()
{
	int board_size;
	while (true)
	{
		system("cls");
		std::cout << "Choose the board size: ";
		std::cin>> board_size;

		if(!validate_int(board_size)) continue;
		
		if (board_size > 3) return board_size;
		
		freeze_screen("The board size must be greater than 3!");
	}
}