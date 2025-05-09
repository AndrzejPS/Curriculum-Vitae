#include "Dijkstra's Algorithm.h"
#include <algorithm>

void DijkstrasAlgorithm(const int& starting_spot, const std::unordered_map<int, connections>& vertex_connections, std::unordered_map<int, double>& shortest_distances, std::unordered_map<int, bool>& visited_places, std::vector<int> temporary_container, std::vector<std::vector<int>>& shortest_paths)
{
	visited_places[starting_spot] = true;
	temporary_container.push_back(starting_spot);

	//if a vertex doesn't lead to any other vertices the case is skipped
	if (vertex_connections.find(starting_spot) == vertex_connections.end()) { shortest_paths.push_back(temporary_container);  return; }

	//container with remaining vertices to check; connection -> std::vector<std::pair<int,double>>
	connections next_spots;

	for (const std::pair<int, double>& connection : vertex_connections.at(starting_spot))
	{
		double new_distance = connection.second + shortest_distances[starting_spot];

		if (shortest_distances[connection.first] > new_distance)
		{
			shortest_distances[connection.first] = new_distance;
			next_spots.push_back(connection);
		}	
	}
	
	//sort the list to get a proper priority
	sortNextSpotsList(next_spots);

	for (const std::pair<int, double>& new_starting_spot : next_spots)
	{
		if (visited_places[new_starting_spot.first] == true) continue;

		DijkstrasAlgorithm(new_starting_spot.first, vertex_connections, shortest_distances, visited_places, temporary_container, shortest_paths);
	}

	shortest_paths.push_back(temporary_container);
}

void sortNextSpotsList(connections& next_spots_container)
{
	auto condition = [](const std::pair<int, double>& element1, const std::pair<int, double>& element2)
		{
			return element1.second < element2.second;
		};

	std::sort(next_spots_container.begin(), next_spots_container.end(), condition);
}