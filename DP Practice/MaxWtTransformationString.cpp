#include<bits/stdc++.h>
using namespace std;


int fn(int i, int n, string &s, vector<int> &dp) {
    if(i == n-1) return 1;
    if(i >= n) return 0;
    if(dp[i] != -1) return dp[i];
    
    int alternate = 0, toggle = 0, ch3 = 0;
    // * Choice 1: Check by toggling if required
    if(i < n-1 && s[i] == s[i+1])
        toggle = 3 + fn(i + 2, n, s, dp);
    
    // * Choice 2: Check by adding 4 if already alternate
    if(i < n - 1 && s[i] != s[i + 1])
        alternate = 4 + fn(i + 2, n, s, dp);
        
    // * Choice 2: Check as it is a single char
    ch3 = 1 + fn(i + 1, n, s, dp);
    
    return dp[i] = max({ch3, toggle, alternate});
        
    
}
int getMaxWeight(string &s) {
    int n = s.size();
    vector<int> dp(n, - 1);
    if(n == 1) return 1;
    return fn(0, n, s, dp);
}