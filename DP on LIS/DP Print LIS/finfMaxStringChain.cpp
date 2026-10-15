#include<bits/stdc++.h>
using namespace std;

// * Function to compare 2 strings based on the characters
// * To check if the second string can be formed by removing one character from the first string
bool checkPossible(string &s1, string &s2){
    if(s1.size() - 1 != s2.size()) 
        return false;
    int i = 0, j = 0, n = s1.size(), m = s2.size();
    while(i < n){
        if(j < m && s1[i] == s2[j])
            i++,j++;
        else i++;
    }
    if(i == n && j == m) return true;
    return false;
}
bool static compare(string &s1, string s2){
    return s1.size() < s2.size();
}
// * TC: O(N^2 * L) where N is the number of strings and L is the max length of any word
int longestStringChain(vector<string>& words) {
        sort(words.begin(), words.end(), compare);
        int n = words.size();
        vector<int> dp(n, 1);
        int maxi = 1;
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(checkPossible(words[i], words[j]) && dp[j] + 1 > dp[i]){
                    dp[i] = dp[j] + 1;
                    maxi = max(maxi, dp[i]);
                }
            }
        }
        return maxi;
}

