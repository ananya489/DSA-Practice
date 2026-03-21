#include <iostream>
#include <vector>
using namespace std;

void solve(int open, int close, string str, vector<string>& ans) {
    // Base case
    if (open == 0 && close == 0) {
        ans.push_back(str);
        return;
    }

    // Add '(' if available
    if (open > 0) {
        solve(open - 1, close, str + "(", ans);
    }

    // Add ')' only if valid
    if (close > open) {
        solve(open, close - 1, str + ")", ans);
    }
}

int main() {
    int n = 3;
    vector<string> ans;

    solve(n, n, "", ans);

    cout << "Valid Parentheses:\n";
    for (auto s : ans) {
        cout << s << endl;
    }

    return 0;
}