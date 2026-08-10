#include<bits/stdc++.h>
using namespace std;

// * Recursion
int f(int idx, vector<int>& nums) {
  if(idx < 0) return 0;
  if(idx == 0) return nums[0];

  int pick = 0, notPick = 0;
  pick = f(idx - 2, nums) + nums[idx];
  notPick = f(idx - 1, nums);
  return max(pick, notPick);
}
int nonAdjacent(vector<int>& nums) {
  int idx = nums.size();
  return f(idx-1, nums);
}

// * Memoization
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
// * Only Tabulation
int nonAdjacent(vector<int>& nums) {
  int n = nums.size();
  // vector<int> dp(n, -1);
  int prev2 = 0, prev1 = nums[0];
  for(int i = 1; i < n; i++) {
      int pick = 0, notPick = 0;
      pick = nums[i];
      if(i > 1) pick += prev2;
      notPick = prev1;
      int curri = max(pick, notPick);
      prev2 = prev1;
      prev1 = curri;
  }
  return prev1;
}
// * Tabulation space optimized
int nonAdjacent(vector<int>& nums) {
  int n = nums.size();
  // vector<int> dp(n, -1);
  // dp[0] = nums[0];
  int prev2 = 0, prev1 = nums[0], curri = 0;
  for(int i = 1; i < n; i++) {
      int pick = 0, notPick = 0;
      pick = nums[i];
      if(i > 1) pick += prev2;
      notPick = prev1;
      curri = max(pick, notPick);
      prev2 = prev1;
      prev1 = curri;
  }
  return prev1;
}