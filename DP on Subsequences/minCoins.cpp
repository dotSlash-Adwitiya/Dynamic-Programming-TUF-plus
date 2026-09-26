#include<bits/stdc++.h>
using namespace std;

// * Recursive approach
// * Time Complexity: O(2^n) where n is the number of coins
// * Space Complexity: O(amount) for recursion stack
int f(int i, int amt, vector<int>& coins) {
    if(amt == 0) return 0;
    if(amt < 0 || i == coins.size()) return INT_MAX;

    int ways = INT_MAX;

    for(int idx = i; idx < coins.size(); idx++){
        int maxNoOfCoins = f(idx, amt - coins[idx], coins);
        if(maxNoOfCoins != INT_MAX)
            ways = min(ways, 1 + maxNoOfCoins);
        
    }
    return ways;
}
int MinimumCoins(vector<int>& coins, int amount) {
    int ans = f(0, amount, coins);
    return (ans == INT_MAX ? -1 : ans);
}

// * Memoization approach
// * Time Complexity: O(n*amount) where n is the number of coins
// * Space Complexity: O(n*amount) + O(amount) for recursion stack
int f(int i, int amt, vector<int>& coins, vector<vector<int>> &dp) {
    if(amt == 0) return 0;
    if(amt < 0 || i == coins.size()) return INT_MAX;
    if(dp[i][amt] != -1) return dp[i][amt];
    int ways = INT_MAX;

    for(int idx = i; idx < coins.size(); idx++){
        int noOfCoins = f(idx, amt - coins[idx], coins, dp);
        if(noOfCoins != INT_MAX)
            ways = min(ways, 1 + noOfCoins);
    }
    return dp[i][amt] = ways;
}

// * Tabulation approach
// * Time Complexity: O(n*amount) where n is the number of coins
// * Space Complexity: O(n*amount)
int MinimumCoins(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int> (amount + 1, INT_MAX));
    // int ans = f(0, amount, coins, dp);
    for(int i = 0; i < n; i++)
        dp[i][0] = 0;

    for(int i = n-1; i >= 0; i--) {
        for(int amt = 1; amt <= amount; amt++) {
            int ways = INT_MAX;

            for(int idx = i; idx < coins.size(); idx++){
                if (amt >= coins[idx]) {

                    int noOfCoins =
                        dp[idx][amt - coins[idx]];

                    if (noOfCoins != INT_MAX)
                        ways = min(ways, 1 + noOfCoins);
                }
            }
            dp[i][amt] = ways;
        }
    }

    return (dp[0][amount] == INT_MAX ? -1 : dp[0][amount]);
}