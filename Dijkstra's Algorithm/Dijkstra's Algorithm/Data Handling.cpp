#include "Data Handling.h"
#include <iterator>
#include <algorithm>

std::unordered_set<int> getAllVerticesInGraph(const std::vector<Line_segment>& graph)
{
	std::unordered_set<int> verteces;

	for (const Line_segment& segment : graph)
	{
		verteces.insert(segment.starting_vertex);
		verteces.insert(segment.ending_vertex);
	}

	return verteces;
}

std::unordered_map<int, double> prepareContainerForAlgorithm(const std::unordered_set<int> all_vertices, const int& starting_spot)
{
	std::unordered_map<int, double> vertices_with_distances;

	auto map_element = [](const int& vertix)
		{
			return std::make_pair(vertix, std::numeric_limits<double>::infinity());
		};

	std::transform(all_vertices.begin(), all_vertices.end(), std::inserter(vertices_with_distances, vertices_with_distances.begin()), map_element);

	//starting spot for all possible paths in the graph
	vertices_with_distances[starting_spot] = 0.0;

	return vertices_with_distances;
}