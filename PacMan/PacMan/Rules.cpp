#include "Rules.h"

bool chechWinCondtition(const int& score, const int& board_fields)
{
	//-1 to remove a player spawn pool
	return score == (board_fields -1); 
}