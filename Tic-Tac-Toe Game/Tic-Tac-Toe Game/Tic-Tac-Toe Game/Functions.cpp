#include "Functions.h"
#include "Players.h"
#include <iostream>

bool win_conditions(std::vector<std::vector<char>>& board, const int& board_size, profile& player)
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
		if (counter == board_size-1)  return true;
		else counter = 0;
	}

	//vertically
	for (int j = 0; j < board_size; j++)
	{
		for (int i = 1; i < board_size; i++)
		{
			if (board[i-1][j] == board[i][j] && board[i][j] != ' ') counter++;
			else break;
		}
		if (counter == board_size-1)  return true;
		else counter = 0;
	}

	//diagonally up-down
	for (int i = 1; i < board_size; i++)
	{ 
		int j = i;
		if (board[i-1][j-1] == board[i][j] && board[i][j] != ' ') counter++;
	}
	if (counter == board_size - 1) return true;
	else counter = 0;

	//diagonally down-up
	for (int i = board_size - 1; i > 0; i--)
	{
		int j = board_size -1 - i;
		if (board[i-1][j+1] == board[i][j] && board[i][j] != ' ') counter++;
	}
	if (counter == board_size - 1)  return true;
	
	return false;
}

int check_game_results()
{
	if (win_conditions) return 0;
	else if (!free_spaces) return 1;
	
	return 2;
}

bool free_spaces(std::vector<std::vector<char>>& board)
{
	for (std::vector<char> &fields : board)
	{
		for (char& freespaces : fields)
		{
			if (freespaces == ' ') return true;
		}
	}

	return false;
}

void freeze_screen()
{
	std::cin.get();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

char rematch()
{
	system("cls");
	std::cout << "Do you want to play once more?[Y/N]\n";
	char choice;
	
	while(true)
	{
		std::cin >> choice;
		choice = toupper(choice);
		if (choice != 'Y' && choice != 'N')
		{
			std::cout << "You've chosen a wrong letter! Pls, try again: ";
			continue;
		}

		break;
	}

	return choice;
}

