#pragma once
#include "Players.h"
#include "Functions.h"
#include <iostream>
#include <vector>

bool win_conditions(std::vector<std::vector<char>>& board, const int& board_size);
bool check_game_results(profile& player1, profile& player2, std::vector<std::vector<char>>& board, const int& board_size);
bool free_spaces(std::vector<std::vector<char>>& board);

