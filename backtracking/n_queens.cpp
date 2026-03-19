#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int row, int col, vector<string>& board, int n) {
    int r = row, c = col;

    // upper diagonal
    while (r >= 0 && c >= 0) {
        if (board[r][c] == 'Q') return false;
        r--; c--;
    }

    // left
    r = row; c = col;
    while (c >= 0) {
        if (board[r][c] == 'Q') return false;
        c--;
    }

    // lower diagonal
    r = row; c = col;
    while (r < n && c >= 0) {
        if (board[r][c] == 'Q') return false;
        r++; c--;
    }

    return true;
}

void solve(int col, vector<string>& board, vector<vector<string>>& ans, int n) {
    if (col == n) {
        ans.push_back(board);
        return;
    }

    for (int row = 0; row < n; row++) {
        if (isSafe(row, col, board, n)) {
            board[row][col] = 'Q';
            solve(col + 1, board, ans, n);
            board[row][col] = '.'; // backtrack
        }
    }
}

int main() {
    int n = 4;

    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.'));

    solve(0, board, ans, n);

    cout << "Total solutions: " << ans.size() << endl;

    for (auto& sol : ans) {
        cout << "----\n";
        for (auto& row : sol)
            cout << row << endl;
    }

    return 0;
}