#include "Board.h"
#include "PLayer.h"
#include "Rules.h"
#include <conio.h>
#include "Menu.h"
#include <iostream>
#include <thread>


int main()
{
	BoardParameters board_sizes;
	PlayerProfile p1;
	std::vector<std::vector<char>> board = createBoard(chooseBoardSize(board_sizes));
	board_sizes.board_surface_area = (board_sizes.rows_number) * (board_sizes.columns_number);
	generateObstacle(board_sizes, board);
	spawnPlayer(board, board_sizes, p1);
	
	auto start_of_game = std::chrono::steady_clock::now();
	while (true)
	{
		std::cout << "\033[H\033[J"; //clear the console
		drawBoard(board);
		std::cout << "\nScore: " << p1.score << "/" << board_sizes.board_surface_area - 1 - board_sizes.number_of_obstacles; // -1 bc one space is a player spawn pool
		std::cout <<"\nTime: "; showInGameTime(start_of_game); std::cout << '\n';
		if (_kbhit()) movePlayer(board, p1, getPlayerMovement(), board_sizes);
		if (chechWinCondtition(p1.score, board_sizes.board_surface_area, board_sizes.number_of_obstacles)) break; // -1 bc one space is a player spawn pool
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}

	std::cout << "\033[H\033[J";
	drawBoard(board);
	std::cout << "\nTime: "; showInGameTime(start_of_game); std::cout << '\n';
	
}


