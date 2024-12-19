#pragma once
#include "Players.h"
#include "Board.h"

void menu(profile& player, profile& Ai, std::map<int, char>& emblem_collection);
void singleplayer_game(profile& player, profile& Ai, std::map<int, char>& emblem_collection);
void freeze_screen();
char rematch();



