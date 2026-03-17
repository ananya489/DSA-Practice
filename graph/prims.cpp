#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii; // {weight, vertex}

void prims(int V, vector<vector<pii>> &adj) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    vector<int> key(V, 1e9);     // minimum weight to include vertex
    vector<bool> inMST(V, false);

    key[0] = 0;
    pq.push({0, 0}); // {weight, vertex}

    int totalWeight = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        int wt = pq.top().first;
        pq.pop();

        if (inMST[u]) continue;

        inMST[u] = true;
        totalWeight += wt;

        for (auto &edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                pq.push({weight, v});
            }
        }
    }

    cout << "Total weight of MST: " << totalWeight << endl;
}

int main() {
    int V = 5;
    vector<vector<pii>> adj(V);

    // Undirected graph
    adj[0].push_back({1, 2});
    adj[1].push_back({0, 2});

    adj[0].push_back({3, 6});
    adj[3].push_back({0, 6});

    adj[1].push_back({2, 3});
    adj[2].push_back({1, 3});

    adj[1].push_back({3, 8});
    adj[3].push_back({1, 8});

    adj[1].push_back({4, 5});
    adj[4].push_back({1, 5});

    adj[2].push_back({4, 7});
    adj[4].push_back({2, 7});

    prims(V, adj);

    return 0;
}