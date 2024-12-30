#pragma once
#include "Board.h"

struct PlayerProfile
{
	int coordinate_x, coordinate_y;
};

void spawnPlayer(std::vector<std::vector<char>>& board, const BoardParameters& board_size, PlayerProfile& player);
char getPlayerMovement();
void checkMovementResult(std::vector<std::vector<char>>& board, PlayerProfile& player, int distance_x, int distance_y);
void movePlayer(std::vector<std::vector<char>>& board, PlayerProfile& player, char move);