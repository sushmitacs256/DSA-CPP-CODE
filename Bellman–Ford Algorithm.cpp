#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Edge {
    int u, v, w;
};

void bellmanFord(int V, int E, int src, vector<Edge> &edges) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    // Relax edges (V-1) times
    for (int i = 1; i <= V - 1; i++) {
        for (auto &edge : edges) {
            if (dist[edge.u] != INT_MAX && 
                dist[edge.u] + edge.w < dist[edge.v]) {
                dist[edge.v] = dist[edge.u] + edge.w;
            }
        }
    }

    // Check for negative-weight cycles
    for (auto &edge : edges) {
        if (dist[edge.u] != INT_MAX && 
            dist[edge.u] + edge.w < dist[edge.v]) {
            cout << "Graph contains a negative weight cycle!\n";
            return;
        }
    }

    cout << "Shortest distances from source " << src << ":\n";
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX)
            cout << "Node " << i << " : INF\n";
        else
            cout << "Node " << i << " : " << dist[i] << endl;
    }
}

int main() {
    int V = 5; // number of vertices
    int E = 8; // number of edges

    vector<Edge> edges = {
        {0, 1, -1}, {0, 2, 4},
        {1, 2, 3}, {1, 3, 2},
        {1, 4, 2}, {3, 2, 5},
        {3, 1, 1}, {4, 3, -3}
    };

    bellmanFord(V, E, 0, edges);

    return 0;
}
