#pragma once
#include <vector>
#include <string>
#include <map>
#include <random>

struct profile
{
	std::string profile_name; 
	char emblem = ' ';
};

std::vector<std::vector<char>> create_board(const int& board_size);
void write_board(std::vector<std::vector<char>> &board, const int& board_size);
void players_turn(std::vector<std::vector<char>>& board, const int& board_size, profile& player);
int AI_move_generator(int low, int high);
void AI_turn(std::vector<std::vector<char>>& board, const int& board_size, profile& bot);
bool win_conditions(std::vector<std::vector<char>>& board, const int& board_size, profile &player);
int check_game_results();
bool free_spaces(std::vector<std::vector<char>>& board);
int emblem_choice(std::map<int, char>& emblem_collection, profile& player);
void freeze_screen();
void clear_board(std::vector<std::vector<char>>& board);
char rematch();
void random_emblem_for_bot(profile& bot, std::map<int, char>& symbols, int emblem_taken);