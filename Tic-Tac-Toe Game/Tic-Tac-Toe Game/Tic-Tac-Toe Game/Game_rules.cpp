#include "Game_rules.h"

bool win_conditions(std::vector<std::vector<char>>& board, const int& board_size)
{
	int counter = 0;

	//horizontally
	for (int i = 0; i < board_size; i++)
	{
		for (int j = 1; j < board_size; j++)
		{
			if (board[i][j - 1] == board[i][j] && board[i][j] != ' ') counter++;
			else break;
		}
		if (counter == board_size - 1) return true;
		else counter = 0;
	}

	//vertically
	for (int j = 0; j < board_size; j++)
	{
		for (int i = 1; i < board_size; i++)
		{
			if (board[i - 1][j] == board[i][j] && board[i][j] != ' ') counter++;
			else break;
		}
		if (counter == board_size - 1) return true;
		else counter = 0;
	}

	//diagonally up-down
	for (int i = 1; i < board_size; i++)
	{
		int j = i;
		if (board[i - 1][j - 1] == board[i][j] && board[i][j] != ' ') counter++;
	}
	if (counter == board_size - 1) return true;
	else counter = 0;

	//diagonally down-up
	for (int i = board_size - 1; i > 0; i--)
	{
		int j = board_size - 1 - i;
		if (board[i - 1][j + 1] == board[i][j] && board[i][j] != ' ') counter++;
	}
	if (counter == board_size - 1) return true;

	return false;
}

bool free_spaces(std::vector<std::vector<char>>& board)
{
	for (std::vector<char>& fields : board)
	{
		for (char& freespaces : fields)
		{
			if (freespaces == ' ') return true;
		}
	}

	return false;
}

bool check_game_results(profile& player1, profile& player2, std::vector<std::vector<char>>& board, const int& board_size)
{
	if (win_conditions(board, board_size))
	{
		player1.score++;
		std::cout << "End of the game. The winner is " << player1.profile_name << '!' << std::endl;
		std::cout << "The final score: " << player1.profile_name << " (" << player1.score << " wins) - (" << player2.score << " wins) " << player2.profile_name;
		freeze_screen();
		return true;
	}
	else if (!free_spaces(board))
	{
		std::cout << "End of the game. It's a tie!";
		freeze_screen();
		return true;
	}

	return false;
}