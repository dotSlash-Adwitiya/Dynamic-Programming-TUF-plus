#include<bits/stdc++.h>
using namespace std;


int fn(int i, int j,vector<vector<int>>& triangle, vector<vector<int>> &dp) {
  if(dp[i][j] != -1) return dp[i][j];
  if(i == triangle.size() - 1) return triangle[i][j];

  int down = triangle[i][j] + fn(i + 1, j, triangle, dp);
  int diagonal = triangle[i][j] + fn(i + 1, j + 1, triangle, dp);

  return dp[i][j] = min(down, diagonal);
}
int minTriangleSum(vector<vector<int>>& triangle) {
  int row = triangle.size(), col = triangle[0].size();
  vector<vector<int> > dp(row, vector<int> (row, - 1));
  return fn(0, 0, triangle, dp);
}

int minTriangleSum(vector<vector<int>>& triangle) {
  int row = triangle.size(), col = triangle[0].size();
  vector<vector<int> > dp(row, vector<int> (row, - 1));

  for(int j = 0; j < triangle.size(); j++)
      dp[row - 1][j] = triangle[row - 1][j];
  
  for(int i = row - 2; i >= 0; i--){
      for(int j = i; j >= 0; j--) {
          int down = triangle[i][j] + dp[i + 1][j];
          int diagonal = triangle[i][j] + dp[i + 1][j + 1];

          dp[i][j] = min(down, diagonal);
      }
  }
  return dp[0][0];
}