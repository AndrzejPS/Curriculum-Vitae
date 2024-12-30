#include "Board.h"
#include "PLayer.h"
#include "Rules.h"
#include <conio.h>
#include <iostream>

int main()
{
	BoardParameters board_sizes;
	PlayerProfile p1;
	std::vector<std::vector<char>> board = create_board(choose_board_size(board_sizes));
	spawnPlayer(board, board_sizes, p1);
	while (true)
	{
		std::cout << "\033[H\033[J";
		draw_board(board);
		std::cout << "\nScore: " << p1.score << "/" << (board_sizes.rows_number-2)*(board_sizes.columns_number-2) - 1; //-2 to include all spaces without board eadges, -1 bc one space is a player spawn pool
		movePlayer(board, p1, getPlayerMovement());
		if (chechWinCondtition(p1.score, (board_sizes.rows_number - 2) * (board_sizes.columns_number - 2) - 1)) break;
	}
	
}


