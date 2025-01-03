#include "Board.h"
#include "PLayer.h"
#include "Rules.h"
#include <conio.h>
#include <iostream>

int main()
{
	BoardParameters board_sizes;
	PlayerProfile p1;
	std::vector<std::vector<char>> board = createBoard(chooseBoardSize(board_sizes));
	board_sizes.board_surface_area = (board_sizes.rows_number) * (board_sizes.columns_number);
	generateObstacle(board_sizes, board);
	spawnPlayer(board, board_sizes, p1);
	
	while (true)
	{
		std::cout << "\033[H\033[J"; //clear the console
		drawBoard(board);
		std::cout << "\nScore: " << p1.score << "/" << board_sizes.board_surface_area - 1 - board_sizes.number_of_obstacles; // -1 bc one space is a player spawn pool
		movePlayer(board, p1, getPlayerMovement(), board_sizes);
		drawBoard(board);
		if (chechWinCondtition(p1.score, board_sizes.board_surface_area, board_sizes.number_of_obstacles)) break; // -1 bc one space is a player spawn pool
	}

	std::cout << "\033[H\033[J";
	drawBoard(board);
	
}


