#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
};

// Comparator to sort edges by weight
bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

// Disjoint Set (Union-Find)
class DSU {
    vector<int> parent, rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if(parent[x] != x)
            parent[x] = find(parent[x]); // Path compression
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);

        if(px == py) return;

        if(rank[px] < rank[py]) {
            parent[px] = py;
        } else if(rank[px] > rank[py]) {
            parent[py] = px;
        } else {
            parent[py] = px;
            rank[px]++;
        }
    }
};

void kruskal(int V, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(), compare);

    DSU dsu(V);
    int totalWeight = 0;

    cout << "Edges in MST:\n";

    for(auto &edge : edges) {
        if(dsu.find(edge.u) != dsu.find(edge.v)) {
            dsu.unite(edge.u, edge.v);
            totalWeight += edge.weight;

            cout << edge.u << " - " << edge.v 
                 << " : " << edge.weight << endl;
        }
    }

    cout << "Total MST Weight: " << totalWeight << endl;
}

int main() {
    int V = 4;

    vector<Edge> edges = {
        {0,1,10},
        {0,2,6},
        {0,3,5},
        {1,3,15},
        {2,3,4}
    };

    kruskal(V, edges);

    return 0;
}