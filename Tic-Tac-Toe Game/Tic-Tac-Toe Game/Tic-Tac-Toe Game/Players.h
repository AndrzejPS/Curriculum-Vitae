#pragma once
#include <vector>
#include <map>
#include <string>

struct profile
{
	std::string profile_name;
	char emblem = ' ';
};

void players_turn(std::vector<std::vector<char>>& board, const int& board_size, profile& player);
int emblem_choice(std::map<int, char>& emblem_collection, profile& player);

int AI_move_generator(int low, int high);
void AI_turn(std::vector<std::vector<char>>& board, const int& board_size, profile& bot);
void random_emblem_for_bot(profile& bot, std::map<int, char>& symbols, int emblem_taken);