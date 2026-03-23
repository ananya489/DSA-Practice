#include <iostream>
#include <vector>
using namespace std;

int n = 4;

bool isSafe(int x, int y, vector<vector<int>>& maze, vector<vector<int>>& visited) {
    return (x >= 0 && y >= 0 && x < n && y < n &&
            maze[x][y] == 1 && visited[x][y] == 0);
}

void solve(int x, int y, vector<vector<int>>& maze, vector<vector<int>>& visited,
           string path, vector<string>& ans) {

    // Destination reached
    if (x == n - 1 && y == n - 1) {
        ans.push_back(path);
        return;
    }

    visited[x][y] = 1;

    // Down
    if (isSafe(x + 1, y, maze, visited))
        solve(x + 1, y, maze, visited, path + 'D', ans);

    // Left
    if (isSafe(x, y - 1, maze, visited))
        solve(x, y - 1, maze, visited, path + 'L', ans);

    // Right
    if (isSafe(x, y + 1, maze, visited))
        solve(x, y + 1, maze, visited, path + 'R', ans);

    // Up
    if (isSafe(x - 1, y, maze, visited))
        solve(x - 1, y, maze, visited, path + 'U', ans);

    // Backtrack
    visited[x][y] = 0;
}

int main() {
    vector<vector<int>> maze = {
        {1,0,0,0},
        {1,1,0,1},
        {0,1,0,0},
        {1,1,1,1}
    };

    vector<vector<int>> visited(n, vector<int>(n, 0));
    vector<string> ans;

    if (maze[0][0] == 1)
        solve(0, 0, maze, visited, "", ans);

    cout << "Paths:\n";
    for (auto s : ans)
        cout << s << " ";

    return 0;
}