#include "dijkstras.h"

int main() {
    Graph G;
    file_to_graph("small.txt", G);
    vector<int> previous;
    vector<int> distances = dijkstra_shortest_path(G, 0, previous);
    vector<int> path;
    for (int i=0; i < G.numVertices; ++i) {
        path = extract_shortest_path(distances, previous, i);
        print_path(path, distances[i]);
    }
    return 0;
}