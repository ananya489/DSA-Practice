#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int cutRod(vector<int>& price, int n) {
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            int maxProfit = INT_MIN;

            for (int j = 0; j < i; j++) {
                maxProfit = max(maxProfit, price[j] + dp[i - j - 1]);
            }

            dp[i] = maxProfit;
        }

        return dp[n];
    }
};

int main() {
    vector<int> price = {2, 5, 7, 8};
    int n = price.size();

    Solution obj;
    cout << "Maximum Profit: " << obj.cutRod(price, n);

    return 0;
}