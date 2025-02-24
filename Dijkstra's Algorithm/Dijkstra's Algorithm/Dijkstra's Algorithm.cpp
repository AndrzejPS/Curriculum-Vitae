#include "Dijkstra's Algorithm.h"
#include <algorithm>

void DijkstrasAlgorithm(const int& starting_spot, const std::unordered_map<int, connections>& vertex_connections, std::unordered_map<int, double>& shortest_paths, std::unordered_map<int, bool>& visited_places)
{
	visited_places[starting_spot] = true;

	//container with remaining vertices to check; connection -> std::vector<std::pair<int,double>>
	connections next_spots;

	//if a vertex doesn't lead to any other vertices the case is skipped
	if (vertex_connections.find(starting_spot) == vertex_connections.end()) return;

	for (const std::pair<int, double>& connection : vertex_connections.at(starting_spot))
	{
		double new_distance = connection.second + shortest_paths[starting_spot];

		if (shortest_paths[connection.first] > new_distance)
		{
			shortest_paths[connection.first] = new_distance;
			next_spots.push_back(connection);
		}	
	}
	
	//sort the list to get a proper priority
	sortNextSpotsList(next_spots);

	for (const std::pair<int, double>& new_starting_spot : next_spots)
	{
		if (visited_places[new_starting_spot.first] == true) continue;

		DijkstrasAlgorithm(new_starting_spot.first, vertex_connections, shortest_paths, visited_places);
	}

}

void sortNextSpotsList(connections& next_spots_container)
{
	auto condition = [](const std::pair<int, double>& element1, const std::pair<int, double>& element2)
		{
			return element1.second < element2.second;
		};

	std::sort(next_spots_container.begin(), next_spots_container.end(), condition);
}