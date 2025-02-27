#pragma once
#include <unordered_map>
#include <vector>
#include <unordered_set>

using connections = std::vector<std::pair<int, double>>;

//graph shattered into segments
struct Line_segment
{
	int starting_vertex, ending_vertex;
	double distance;
};

std::unordered_map<int, connections> saveVertexConnections(const std::vector<Line_segment>& graph);
std::unordered_set<int> getAllVerticesInGraph(const std::vector<Line_segment>& graph);
std::unordered_map<int, double> prepareContainerForResults(const std::unordered_set<int> all_vertices, const int& starting_spot);
std::unordered_map<int, bool> makeListOfVisitedVertices(const std::unordered_set<int>& all_vertices);
void writeAnswers(const std::vector<std::vector<int>>& paths, const std::unordered_map<int, double>& distances);
