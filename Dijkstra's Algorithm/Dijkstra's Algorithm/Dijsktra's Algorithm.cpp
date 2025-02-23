#include "Dijkstra's Algorithm.h"

void DijkstrasAlgorithm(const int& starting_spot, const std::unordered_map<int, connections>& vertex_connections, std::unordered_map<int, double>& shortest_paths, std::unordered_map<int, bool>& visited_places)
{
	visited_places[starting_spot] = true;
	
	for (const std::pair<int, double>& connection : vertex_connections.at(starting_spot))
	{
		double new_distance = connection.second + shortest_paths[starting_spot];

		if(shortest_paths[connection.first]>new_distance)
			shortest_paths[connection.first] = new_distance;
	}


}

