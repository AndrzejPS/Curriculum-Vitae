#include "Board.h"
#include "PLayer.h"
#include <iostream>

int main()
{
	BoardParameters board_size;
	std::vector<std::vector<char>> board = create_board(choose_board_size(board_size));
	draw_board(board);
	//spawnPlayer(std::vector<std::vector<char>>&board, board_size, PlayerProfile & player)
}


