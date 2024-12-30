#include "Board.h"
#include "PLayer.h"
#include <conio.h>
#include <iostream>

int main()
{
	BoardParameters board_size;
	PlayerProfile p1;
	std::vector<std::vector<char>> board = create_board(choose_board_size(board_size));
	spawnPlayer(board, board_size, p1);
	while (true)
	{
		std::cout << "\033[H\033[J";
		draw_board(board);
		movePlayer(board, p1, getPlayerMovement());
	}
	
}


