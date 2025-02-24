#include "Data Handling.h"

std::unordered_map<int, connections> saveVertexConnections(const std::vector<Line_segment>& graph)
{
	std::unordered_map<int, connections> vertex_connections;

	for (const Line_segment& segment : graph)
	{
		//where the vertex is leading to and how long the path is
		vertex_connections[segment.starting_vertex].push_back({ segment.ending_vertex, segment.distance });
	}

	return vertex_connections;
}

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

std::unordered_map<int, double> prepareContainerForResults(const std::unordered_set<int> all_vertices, const int& starting_spot)
{
	std::unordered_map<int, double> vertices_with_distances;

	//at first all vertices have an infinite distance exept the starting spot
	for (const int& vertex : all_vertices)
	{
		vertices_with_distances[vertex] = std::numeric_limits<double>::infinity();
	}

	//starting spot for all possible paths in the graph
	vertices_with_distances[starting_spot] = 0.0;

	return vertices_with_distances;
}

std::unordered_map<int, bool> makeListOfVisitedVertices(const std::unordered_set<int>& all_vertices)
{
	std::unordered_map<int, bool> visited_vertices;

	for (const int& vertex : all_vertices)
	{
		visited_vertices[vertex];
	}

	return visited_vertices;
}