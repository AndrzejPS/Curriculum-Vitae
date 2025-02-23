#pragma once
#include "Data Handling.h"

void DijkstrasAlgorithm(const std::vector<Line_segment>& graph, const int& starting_spot, std::unordered_map<int, double>& shortest_paths, std::unordered_map<int, bool>& visited_places);


