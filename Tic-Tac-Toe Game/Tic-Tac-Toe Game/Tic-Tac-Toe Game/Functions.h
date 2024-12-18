#pragma once
#include "Players.h"
#include "Functions.h"
#include <vector>
#include <random>

bool win_conditions(std::vector<std::vector<char>>& board, const int& board_size, profile &player);
int check_game_results();
bool free_spaces(std::vector<std::vector<char>>& board);
void freeze_screen();
char rematch();

