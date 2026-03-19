#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int u, v, weight;
};

void bellmanFord(int V, vector<Edge>& edges, int src) {
    vector<int> dist(V, 1e9);

    dist[src] = 0;

    // Relax edges V-1 times
    for (int i = 1; i <= V - 1; i++) {
        for (auto &edge : edges) {
            int u = edge.u;
            int v = edge.v;
            int w = edge.weight;

            if (dist[u] != 1e9 && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Check for negative cycle
    for (auto &edge : edges) {
        int u = edge.u;
        int v = edge.v;
        int w = edge.weight;

        if (dist[u] != 1e9 && dist[u] + w < dist[v]) {
            cout << "Graph contains negative weight cycle\n";
            return;
        }
    }

    // Print result
    cout << "Shortest distances from source:\n";
    for (int i = 0; i < V; i++) {
        cout << "Vertex " << i << " : " << dist[i] << endl;
    }
}

int main() {
    int V = 5;

    vector<Edge> edges = {
        {0,1,-1},
        {0,2,4},
        {1,2,3},
        {1,3,2},
        {1,4,2},
        {3,2,5},
        {3,1,1},
        {4,3,-3}
    };

    bellmanFord(V, edges, 0);

    return 0;
}