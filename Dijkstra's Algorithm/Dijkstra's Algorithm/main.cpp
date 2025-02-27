#include "Data Handling.h"
#include "Dijkstra's Algorithm.h"
#include <iostream>

int main()
{
    std::vector< Line_segment> graph =
    {
        /*type your graph here with this pattern:
           split you graph into line segments and type each one consecutively,
           write int the brackets: {starting vertex, ending vertex, distance between them},
           eg. the line segment - {10,14,13.4} - means that there is a path from the vertex number 10 to the vertex number 14 and the path is 13.4 units long.
        */
    };

    int starting_spot = 16;
    std::unordered_map<int, connections> vertex_connections = saveVertexConnections(graph);
    std::unordered_set<int> all_vertices = getAllVerticesInGraph(graph);
    std::unordered_map<int, double> shortest_distances = prepareContainerForResults(all_vertices, starting_spot);
    std::unordered_map<int, bool> visited_vertices = makeListOfVisitedVertices(all_vertices);
    std::vector<std::vector<int>> shortest_paths;

    //checks if the starting spot is connected with the graph
    if (vertex_connections.find(starting_spot) == vertex_connections.end())
    {
        std::cout << "The starting spot is not connected with the graph!";
    }
    else
    {
        DijkstrasAlgorithm(starting_spot, vertex_connections, shortest_distances, visited_vertices, {}, shortest_paths);

        std::reverse(shortest_paths.begin(), shortest_paths.end());
        writeAnswers(shortest_paths, shortest_distances);
    }
   
}

