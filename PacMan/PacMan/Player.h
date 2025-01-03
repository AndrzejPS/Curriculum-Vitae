#pragma once
#include "Board.h"
#include <string>

struct PlayerProfile
{
	int coordinate_x = 0, coordinate_y=0;
	int score = 0;
	std::string name;
};

void spawnPlayer(std::vector<std::vector<char>>& board, const BoardParameters& board_size, PlayerProfile& player);
char getPlayerMovement();
void checkMovementResult(std::vector<std::vector<char>>& board, PlayerProfile& player, int distance_x, int distance_y, const BoardParameters& board_symbols);
void movePlayer(std::vector<std::vector<char>>& board, PlayerProfile& player, char move, const BoardParameters& board_symbols);
void addPointToPlayer(int& score);