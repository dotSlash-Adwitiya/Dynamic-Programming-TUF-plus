#include<bits/stdc++.h>
using namespace std;

// * Memoization Approach
 int f(int idx, vector<int>& nums, vector<int>& dp) {
  if(idx < 0) return 0;
  if(idx == 0) return nums[0];
  if(dp[idx] != -1) return dp[idx];

  int pick = 0, notPick = 0;
  pick = f(idx - 2, nums, dp) + nums[idx];
  notPick = f(idx - 1, nums, dp);
  return dp[idx] = max(pick, notPick);
}
int nonAdjacent(vector<int>& nums) {
  int idx = nums.size();
  vector<int> dp(idx, -1);
  return f(idx-1, nums, dp);
}

// * Tabulation Apprach, TC: O(N), SC:O(N)
int nonAdjacent(vector<int>& nums) {
  int n = nums.size();
  vector<int> dp(n, -1);
  dp[0] = nums[0];
  for(int i = 1; i < n; i++) {
      int pick = 0, notPick = 0;
      pick = nums[i];
      if(i > 1) pick += dp[i-2];
      notPick = dp[i - 1];
      dp[i] = max(pick, notPick);
  }
  return dp[n-1];
}