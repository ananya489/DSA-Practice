#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;

void dijkstra(int V, vector<vector<pair<int,int>>> &adj, int src) {

    vector<int> dist(V, INF);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while(!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        for(auto edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if(dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Shortest distances from source:\n";
    for(int i = 0; i < V; i++)
        cout << "Vertex " << i << " : " << dist[i] << endl;
}

int main() {

    int V = 5;

    vector<vector<pair<int,int>>> adj(V);

    adj[0].push_back({1,4});
    adj[0].push_back({2,1});
    adj[2].push_back({1,2});
    adj[1].push_back({3,1});
    adj[2].push_back({3,5});
    adj[3].push_back({4,3});

    dijkstra(V, adj, 0);

    return 0;
}