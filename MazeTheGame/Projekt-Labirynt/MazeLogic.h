#pragma once
#include <vector>
#include <string>

class MazeLogic
{
public:
	enum class chars_legend {
								edge = '#', meta = 'M', obstacle = 'O', path = ' ',
								player = 'P', enemy = 'E', teleport = 'T', key = 'K'
							};

private:
	//private variables
	const unsigned int maze_height, maze_width;
	std::vector<std::vector<chars_legend>> maze;

	const int teleport_max_num = 2;
	const int enemy_max_num = 3;

	//private methods

	void addEdges();
	void addPaths();
	void addShortCuts();
	void addMeta();
	void addPlayerSpawner();
	void addTeleport();
	void addEnemiesSpawner();
	void addKey();
	void addObject(const chars_legend& object, const int& max_num = 1, const std::vector<int>& minimal_distance = {}, const std::vector<chars_legend>& avoid_objects = {}, const bool& clear_area = false, const int& clearing_area = 0);
	void generateMaze(const int& starting_spot_x, const int& starting_spot_y);
	void clearTilesAround(const std::pair<int, int>& coords, const int& distance);
	bool isNear(const std::pair<int, int>& coords, const chars_legend& object_representation, const int& distance) const;
	char toChar(const chars_legend& enum_character) const;
	int rand_int(int low, int high);

public:
	

	//construktor & destructor
	MazeLogic(const unsigned int& height, const unsigned int& width);
	~MazeLogic() {};

	//public methods

	static std::string makeString(chars_legend key);

	inline std::vector< std::vector<chars_legend>> getMaze() const
	{
		return this->maze;
	}

	inline std::pair<int, int> getMazeSize() const
	{
		return { this->maze_height, this->maze_width };
	}

	inline std::pair<int,int> getPlayerSpawnerCoords() const
	{
		for (size_t i = 0; i < maze_height; i++)
		{
			for (size_t j = 0; j < maze_height; j++)
			{
				if (maze[i][j] == chars_legend::player) return { i, j };
			}
		}
	}

	//for testing
	void printMaze();
};