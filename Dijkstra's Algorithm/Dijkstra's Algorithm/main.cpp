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

    int starting_spot = 2;
    std::unordered_map<int, connections> vertex_connections = saveVertexConnections(graph);
    std::unordered_set<int> all_vertices = getAllVerticesInGraph(graph);
    std::unordered_map<int, double> results = prepareContainerForResults(all_vertices, starting_spot);
    std::unordered_map<int, bool> visited_vertices = makeListOfVisitedVertices(all_vertices);

    DijkstrasAlgorithm(starting_spot, vertex_connections, results, visited_vertices);

    for (const std::pair<int, double>& value : results)
    {
        std::cout << value.first << " " << value.second << std::endl;
    }
}

