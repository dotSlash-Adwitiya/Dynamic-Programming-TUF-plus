#include<bits/stdc++.h>
using namespace std;

/*
  * When to skip is important, 
  * it can't be written as a separate case
  * 
*/

int fn(int i, int j, vector<vector<int>> &dp){
  if(i == 0 && j == 0) return 1;
  if(i < 0 || j < 0) return 0;
  
  if(dp[i][j] != -1) return dp[i][j];
  // * Move bottom
  int up = fn(i - 1, j, dp);
  // * Move Right
  int left = fn(i, j - 1, dp);

  return dp[i][j] = left + up;

}
int uniquePaths(int m, int n) {
  if(n == 1 && m == 1) return 1;
  vector<vector<int>> dp(m, vector<int> (n, -1));
  
  fn(m-1, n-1, dp);

  return dp[m-1][n-1];
}


int uniquePaths(int m, int n) {
  if(n == 1 && m == 1) return 1;
  vector<vector<int>> dp(m, vector<int> (n, -1));
  dp[0][0] = 1;

  for(int i = 0; i < m; i++) {
      for(int j = 0; j < n; j++){
          int down = 0, right = 0; 
          if(i == 0 && j == 0) continue;
          // * Move UP
          if(i > 0) down = dp[i - 1][j];
          // * Move Left
          if(j > 0) right = dp[i][j - 1];

          dp[i][j] = right + down;
      }
  }
  return dp[m-1][n-1];
}