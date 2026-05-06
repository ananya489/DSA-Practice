#include <iostream>
#include <vector>
using namespace std;

int coinChange(vector<int>& coins, int amount) {

    // Create DP array
    vector<int> dp(amount + 1, amount + 1);

    // Base case
    dp[0] = 0;

    // Fill DP array
    for (int i = 1; i <= amount; i++) {

        for (int coin : coins) {

            if (coin <= i) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    // If amount cannot be formed
    if (dp[amount] > amount)
        return -1;

    return dp[amount];
}

int main() {

    vector<int> coins = {1, 2, 5};
    int amount = 11;

    int result = coinChange(coins, amount);

    cout << "Minimum coins required: " << result << endl;

    return 0;
}