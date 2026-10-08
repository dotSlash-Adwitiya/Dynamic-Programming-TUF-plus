#include<bits/stdc++.h>
using namespace std;

// * f(3, 0) -> represents length of LIS starting from 3rd index,
// * whose prev index is 0. f(idx, prev_idx)

// * Recursive Approach
// * Time Complexity: O(2^n)
// * Space Complexity: O(n) -> Recursion Stack
int f(int idx, int prevIdx, vector<int>& nums) {
    if(idx == nums.size()) return 0;

    int notTake = f(idx + 1, prevIdx, nums);
    int take = 0;
    if(prevIdx == INT_MIN || nums[idx] > prevIdx)
        take = 1 + f(idx + 1, nums[idx], nums);

    return max(take, notTake);

}
int LIS(vector<int>& nums) {
    return f(0, INT_MIN, nums);
}   

// * Memoization Approach
// * Time Complexity: O(n^2)
// * Space Complexity: O(n^2) + O(n) -> Recursion Stack
int f(int idx, int prevIdx, vector<int>& nums, vector<vector<int>> &dp) {
    if(idx == nums.size()) return 0;
    if(dp[idx][prevIdx + 1] != -1) return dp[idx][prevIdx + 1];

    int notTake = f(idx + 1, prevIdx, nums, dp);
    int take = 0;
    if(prevIdx == -1 || nums[idx] > nums[prevIdx])
        take = 1 + f(idx + 1, idx, nums, dp);

    return dp[idx][prevIdx + 1] = max(take, notTake);

}
int LIS(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int> (n + 1, -1));
    return f(0, -1, nums, dp);
}

// * Tabulation Approach
// * Time Complexity: O(n^2)
// * Space Complexity: O(n^2)
int f(int idx, int prevIdx, vector<int>& nums, vector<vector<int>> &dp) {
    if(idx == nums.size()) return 0;
    if(dp[idx][prevIdx + 1] != -1) return dp[idx][prevIdx + 1];

    int notTake = f(idx + 1, prevIdx, nums, dp);
    int take = 0;
    if(prevIdx == -1 || nums[idx] > nums[prevIdx])
        take = 1 + f(idx + 1, idx, nums, dp);

    return dp[idx][prevIdx + 1] = max(take, notTake);

}
int LIS(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int> (n + 1, -1));
    return f(0, -1, nums, dp);
}

// * LIS using Binary Search
// * Time Complexity: O(nlogn)
// * Space Complexity: O(n)
int LIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> lis;
    lis.push_back(nums[0]);

    for(int i = 1; i < n; i++){
        if(nums[i] > lis.back())
            lis.push_back(nums[i]);
        else {
            int idx = lower_bound(lis.begin(), lis.end(), nums[i]) - lis.begin();
            lis[idx] = nums[i];
        }
    }

    return lis.size();
}  

// * Time Complexity: O(n^2)
// * LIS using specialized Tabulation
// * Space Complexity: O(n)
int LIS(vector<int>& nums) {
    int n = nums.size();
    // vector<int> lis;
    vector<int> dp(n, 1);
    int maxi = 1;
    for(int i = 0; i < n; i++){
        for(int prev = 0; prev <= i - 1; prev++){
            if(nums[prev] < nums[i])
                dp[i] = max(1 + dp[prev], dp[i]);   
        }
        maxi = max(maxi, dp[i]);
    }
    return maxi;
} 