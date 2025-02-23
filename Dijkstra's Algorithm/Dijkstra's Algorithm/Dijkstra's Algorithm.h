#pragma once
#include "Data Handling.h"

void DijkstrasAlgorithm(const int& starting_spot, const std::unordered_map<int, connections>& vertex_connections, std::unordered_map<int, double>& shortest_paths, std::unordered_map<int, bool>& visited_places);
void sortNextSpotsList(connections& next_spots_container);

