#include <algorithm>
#include "dijkstras.h"

using namespace std;

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous) {
    int n = G.numVertices;

    vector<int> distances(n, INF);
    vector<bool> visited(n, false);
    previous.resize(n, -1);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // pair<vertex, weight>

    distances[source] = 0;
    pq.push({0, source});

    while(!pq.empty()) {
        int src = pq.top().second;
        pq.pop();
        if (visited[src]) continue;
        visited[src] = true;
        for (Edge edge: G[src]) {
            int dest = edge.dst;
            int weight = edge.weight;
            if (!visited[dest] && 
                distances[src] + weight < distances[dest]) {
                distances[dest] = distances[src] + weight;
                previous[dest] = src;
                pq.push({distances[dest], dest});
            }
        }
    }

    return distances;
}

vector<int> extract_shortest_path(const vector<int>& distances, const vector<int>& previous, int destination) {
    vector<int> path;
    for (int curr_v=destination; curr_v != -1; curr_v=previous[curr_v])
        path.push_back(curr_v);
    reverse(path.begin(), path.end());
    return path;
}

void print_path(const vector<int>& v, int total) {
    for (int vertex: v)
        cout << vertex << " ";
    cout << endl << "Total cost is " << total << endl;
}