#include <bits/stdc++.h>
using namespace std;

int MOD = 1e9 + 7;


int MOD = 1e9 + 7;

// Recursive function to calculate the minimum and maximum product path to reach cell (i, j)
// * Time Complexity: O(2^(n+m)) - 
// * Exponential time complexity due to the recursive nature of the function
pair<long long, long long> f(
    int i, int j,
    vector<vector<int>>& grid,
    int n, int m,
    vector<vector<long long>>& minDP,
    vector<vector<long long>>& maxDP
) {
    if(i == 0 && j == 0)
        return {grid[i][j], grid[i][j]};

    if(minDP[i][j] != LLONG_MAX && maxDP[i][j] != LLONG_MIN)
        return {minDP[i][j], maxDP[i][j]};

    long long currCell = grid[i][j];

    // Top row -> can only come from left
    if(i == 0) {
        auto firstRow = f(i, j - 1, grid, n, m, minDP, maxDP);

        minDP[i][j] = min(currCell * firstRow.first,
                        currCell * firstRow.second);

        maxDP[i][j] = max(currCell * firstRow.first,
                        currCell * firstRow.second);

        return {minDP[i][j], maxDP[i][j]};
    }

    // Left column -> can only come from above
    if(j == 0) {
        auto firstCol = f(i - 1, j, grid, n, m, minDP, maxDP);

        minDP[i][j] = min(currCell * firstCol.first,
                        currCell * firstCol.second);

        maxDP[i][j] = max(currCell * firstCol.first,
                        currCell * firstCol.second);

        return {minDP[i][j], maxDP[i][j]};
    }

    // Can come from left OR above
    auto left = f(i, j - 1, grid, n, m, minDP, maxDP);
    auto up = f(i - 1, j, grid, n, m, minDP, maxDP);

    minDP[i][j] = min({
        currCell * left.first,
        currCell * left.second,
        currCell * up.first,
        currCell * up.second
    });

    maxDP[i][j] = max({
        currCell * left.first,
        currCell * left.second,
        currCell * up.first,
        currCell * up.second
    });

    return {minDP[i][j], maxDP[i][j]};
}


// * Memoization approach to calculate the maximum product path in a grid
// * Time Complexity: O(n*m) -
// * Space Complexity: O(n*m) - for the memoization tables
pair<long long, long long> f(
    int i, int j,
    vector<vector<int>>& grid,
    int n, int m,
    vector<vector<long long>>& minDP,
    vector<vector<long long>>& maxDP
) {
    if(i == 0 && j == 0)
        return {grid[i][j], grid[i][j]};

    if(minDP[i][j] != LLONG_MAX && maxDP[i][j] != LLONG_MIN)
        return {minDP[i][j], maxDP[i][j]};

    long long currCell = grid[i][j];

    // Top row -> can only come from left
    // * In order to prevent invalid case like - f(-1, {0,1,2...n})
    if(i == 0) {
        auto firstRow = f(i, j - 1, grid, n, m, minDP, maxDP);

        minDP[i][j] = min(currCell * firstRow.first,
                        currCell * firstRow.second);

        maxDP[i][j] = max(currCell * firstRow.first,
                        currCell * firstRow.second);

        return {minDP[i][j], maxDP[i][j]};
    }

    // Left column -> can only come from above
    // * In order to prevent invalid case like - f({0,1,2...n}, -1)
    if(j == 0) {
        auto firstCol = f(i - 1, j, grid, n, m, minDP, maxDP);

        minDP[i][j] = min(currCell * firstCol.first,
                        currCell * firstCol.second);

        maxDP[i][j] = max(currCell * firstCol.first,
                        currCell * firstCol.second);

        return {minDP[i][j], maxDP[i][j]};
    }

    // Can come from left OR above
    auto left = f(i, j - 1, grid, n, m, minDP, maxDP);
    auto up = f(i - 1, j, grid, n, m, minDP, maxDP);

    minDP[i][j] = min({
        currCell * left.first,
        currCell * left.second,
        currCell * up.first,
        currCell * up.second
    });

    maxDP[i][j] = max({
        currCell * left.first,
        currCell * left.second,
        currCell * up.first,
        currCell * up.second
    });

    return {minDP[i][j], maxDP[i][j]};
}

int maxProductPath(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<long long>> minDP(n, vector<long long>(m, LLONG_MAX));
    vector<vector<long long>> maxDP(n, vector<long long>(m, LLONG_MIN));

    auto ans = f(n - 1, m - 1, grid, n, m, minDP, maxDP);

    if(ans.second < 0)
        return -1;

    return ans.second % MOD;
}