#include<bits/stdc++.h>
using namespace std;

// * Memoization Solution
// * TC: O(N*4), SC: O(N) + O(N*4)
int fn(int day, int last, vector<vector<int>>& points, vector<vector<int>>& dp){
  if(day == 0){
      int maxi = 0;
      for(int task = 0; task < 3; task++){
          if(task != last)
              maxi = max(maxi, points[0][task]);
      }
      return dp[day][last] = maxi;
  }
  if(dp[day][last] != -1) return dp[day][last];
  int maxi = 0;
  

  for(int task = 0; task < 3; task++){
      if(task != last){
          int point = fn(day - 1, task, points, dp) + points[day][task];
          maxi = max(maxi, point);
      }
  }
  return dp[day][last] = maxi;
}
int ninjaTraining(vector<vector<int>>& matrix) {
  int days = matrix.size();
  vector<vector<int>> dp(days, vector<int> (4, -1));
  int last = 3;
  return fn(days - 1, last, matrix, dp);
}