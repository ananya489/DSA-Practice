#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

// Floyd Warshall Function
void floydWarshall(int n, vector<vector<int>> &dist) {

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j],
                                     dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

// Print Matrix
void printMatrix(int n, vector<vector<int>> &dist) {

    cout << "Shortest Distance Matrix:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {

    int n, e;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> e;

    vector<vector<int>> dist(n, vector<int>(n, INF));

    // Distance to itself = 0
    for (int i = 0; i < n; i++) {
        dist[i][i] = 0;
    }

    cout << "Enter edges (u v weight):\n";

    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        dist[u - 1][v - 1] = w;
    }

    floydWarshall(n, dist);

    printMatrix(n, dist);

    return 0;
}