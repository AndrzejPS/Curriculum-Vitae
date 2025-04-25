#include "MazeLogic.h"
#include <random>
#include <iostream>

//private methods
void MazeLogic::addEdges()
{
	for (size_t i = 0; i < this->maze_height; i++)
	{
		for (size_t j = 0; j < this->maze_width; j++)
		{
			if (i == 0 || i == this->maze_height - 1 || j == 0 || j == this->maze_width - 1)
				maze[i][j] = chars_legend::edge;
		}
	}
}

void MazeLogic::addPaths()
{
	int starting_spot_x = rand_int(1, this->maze_height - 2);
	int starting_spot_y = rand_int(1, this->maze_width - 2);

	if (starting_spot_x % 2 == 0) starting_spot_x--;
	if (starting_spot_y % 2 == 0) starting_spot_y--;

	this->generateMaze(starting_spot_x, starting_spot_y);
}

void MazeLogic::addShortCuts()
{
	for (auto& rows : this->maze)
	{
		for (auto& tile : rows)
		{
			if (tile == chars_legend::obstacle && rand_int(1, 4) == 1)
				tile = chars_legend::path;
		}
	}
}

void MazeLogic::addMeta()
{
	int meta_x, meta_y;
	switch (rand_int(1, 4))
	{
	case 1: meta_x = 0; meta_y = rand_int(1, this->maze_width - 2); break;
	case 2: meta_x = this->maze_height - 1; meta_y = rand_int(1, this->maze_width - 2); break;
	case 3: meta_x = rand_int(1, this->maze_height - 2); meta_y = 0; break;
	case 4: meta_x = rand_int(1, this->maze_height - 2); meta_y = this->maze_width - 1; break;
	}

	maze[meta_x][meta_y] = chars_legend::meta;
	this->clearTilesAround({ meta_x, meta_y }, 1);
}

void MazeLogic::addPlayerSpawner()
{
	int player_spawner_x, player_spawner_y;
	do {
		player_spawner_x = rand_int(1, this->maze_height - 2);
		player_spawner_y = rand_int(1, this->maze_width - 2);
	} while (
		maze[player_spawner_x][player_spawner_y] != chars_legend::obstacle &&
		maze[player_spawner_x][player_spawner_y] != chars_legend::path);

	maze[player_spawner_x][player_spawner_y] = chars_legend::player;
	this->clearTilesAround({ player_spawner_x, player_spawner_y }, 1);
}

void MazeLogic::addTeleport()
{
	this->addObject(chars_legend::teleport, 2, { 5,1 }, { chars_legend::teleport, chars_legend::meta }, true, 1);
}

void MazeLogic::addEnemiesSpawner()
{
	this->addObject(chars_legend::enemy, 3, { 4,3 }, { chars_legend::player, chars_legend::enemy });
}

void MazeLogic::addKey()
{
	this->addObject(chars_legend::key, 1, { 5,5 }, { chars_legend::meta, chars_legend::player });
}

void MazeLogic::addObject(const chars_legend& object, const int& max_num, const std::vector<int>& minimal_distance, const std::vector<chars_legend>& avoid_objects, const bool& clear_area, const int& clearing_area)
{
	int object_x, object_y, current_num = 0;

	auto isAllNear = [&]()
		{
			for (int i = 0; i < avoid_objects.size(); i++) {
				if (isNear({ object_x, object_y }, avoid_objects[i], minimal_distance[i]))
					return true;
			}
			return false;
		};

	while (current_num++ < max_num)
	{
		do
		{
			object_x = rand_int(1, this->maze_height - 2);
			object_y = rand_int(1, this->maze_width - 2);
		} while (maze[object_x][object_y] != chars_legend::path || isAllNear());

		maze[object_x][object_y] = object;
		if (clear_area) this->clearTilesAround({ object_x, object_y }, clearing_area);
	}
}

void MazeLogic::generateMaze(const int& starting_spot_x, const int& starting_spot_y)
{
	maze[starting_spot_x][starting_spot_y] = chars_legend::path;

	std::vector<std::pair<int, int>> directions{ {{0,2},{0,-2},{2,0},{-2,0}} };
	size_t size = directions.size();
	for (int i = 0; i < size; i++)
		std::swap(directions[i], directions[rand_int(0, size - 1)]);

	for (const auto& pairs : directions)
	{
		int new_x = starting_spot_x + pairs.first;
		int new_y = starting_spot_y + pairs.second;

		if (new_x > 0 && new_x < this->maze_height - 1 &&
			new_y > 0 && new_y < this->maze_width - 1 &&
			maze[new_x][new_y] == chars_legend::obstacle) {
			int new_path_x = starting_spot_x + pairs.first / 2;
			int new_path_y = starting_spot_y + pairs.second / 2;
			maze[new_path_x][new_path_y] = chars_legend::path;
			this->generateMaze(new_x, new_y);
		}
	}
}

void MazeLogic::clearTilesAround(const std::pair<int, int>& coords, const int& distance)
{
	for (int i = -distance; i <= distance; i++)
	{
		for (int j = -distance; j <= distance; j++)
		{
			int x = coords.first + i;
			int y = coords.second + j;
			if (x < 0 || x >= maze_height || y < 0 || y >= maze_width) continue;
			if (maze[x][y] == chars_legend::obstacle)
				maze[x][y] = chars_legend::path;
		}
	}
}

bool MazeLogic::isNear(const std::pair<int, int>& coords, const chars_legend& object_representation, const int& distance) const
{
	for (int i = -distance; i <= distance; i++)
	{
		for (int j = -distance; j <= distance; j++)
		{
			if (i == 0 && j == 0) continue;
			int x = coords.first + i;
			int y = coords.second + j;
			if (x < 0 || x >= maze_height || y < 0 || y >= maze_width) continue;
			if (maze[x][y] == object_representation) return true;
		}
	}
	return false;
}

char MazeLogic::toChar(const chars_legend& enum_character) const
{
	return static_cast<char>(enum_character);
}

std::string MazeLogic::makeString(chars_legend key)
{
	switch (key)
	{
	case chars_legend::edge:      return "edge";
	case chars_legend::meta:      return "meta";
	case chars_legend::obstacle:  return "obstacle";
	case chars_legend::path:      return "path";
	case chars_legend::player:    return "player";
	case chars_legend::enemy:     return "enemy";
	case chars_legend::teleport:  return "teleport";
	case chars_legend::key:       return "key";
	default: std::cerr << "Error::MazeLogic::makeString: The given enum does not exist!";
			 return "Unknown";
	}
}

int MazeLogic::rand_int(int low, int high)
{
	static std::default_random_engine re{ std::random_device{}() };
	using Dist = std::uniform_int_distribution<int>;
	static Dist uid{};
	return uid(re, Dist::param_type{ low,high });
}

MazeLogic::MazeLogic(const unsigned int& height, const unsigned int& width) : maze_height(height), maze_width(width)
{
	this->maze = std::vector<std::vector<chars_legend>>(maze_height, std::vector<chars_legend>(maze_width, chars_legend::obstacle));
	this->addPaths();
	this->addEdges();
	this->addShortCuts();
	this->addMeta();
	this->addPlayerSpawner();
	this->addTeleport();
	this->addEnemiesSpawner();
	this->addKey();
	this->printMaze();
}

void MazeLogic::printMaze()
{
	for (const auto& row : maze) {
		for (const auto& field : row) {
			std::cout << static_cast<char>(field) << " ";
		}
		std::cout << "\n";
	}
}