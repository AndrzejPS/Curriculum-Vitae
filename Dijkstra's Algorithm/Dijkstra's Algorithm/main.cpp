#include "Data Handling.h"
#include "Dijkstra's Algorithm.h"
#include <iostream>

int main()
{
    std::vector< Line_segment> graph =
    {
        {0,1,4.5},
        {0,2,2.31},
        {1,0,6.7},
        {1,2,3},
        {1,3,2},
        {1,4,3},
        {2,1,1.12},
        {2,3,4},
        {2,4,5},
        {3,7,12.18},
        {4,3,1}
    };

    int starting_spot = 0;
    std::unordered_map<int, connections> vertex_connections = saveVertexConnections(graph);
    std::unordered_set<int> all_vertices = getAllVerticesInGraph(graph);
    std::unordered_map<int, double> shortest_distances = prepareContainerForResults(all_vertices, starting_spot);
    std::unordered_map<int, bool> visited_vertices = makeListOfVisitedVertices(all_vertices);
    std::vector<std::vector<int>> shortest_paths;

    DijkstrasAlgorithm(starting_spot, vertex_connections, shortest_distances, visited_vertices,{}, shortest_paths);

    std::reverse(shortest_paths.begin(), shortest_paths.end());
    for (const std::vector<int>& paths : shortest_paths)
    {
        for (const int& path : paths)
        {
            if (path == paths.back()) std::cout << path << " : ";
            else std::cout << path << " -> ";
        }
        std::cout << shortest_distances[paths.back()] << std::endl;
    }
}

