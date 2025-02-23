#pragma once
#include <unordered_map>
#include <vector>
#include <unordered_set>

struct Line_segment
{
	int starting_vertex, ending_vertex;
	double distance;
};

std::unordered_set<int> getAllVerticesInGraph(const std::vector<Line_segment>& graph);
std::unordered_map<int, double> prepareContainerForAlgorithm(const std::unordered_set<int> all_vertices);