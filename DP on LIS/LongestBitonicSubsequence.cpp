#include<bits/stdc++.h>
using namespace std;

// * Time Complexity: O(n^2)
// * Space Complexity: O(n)
// * Intuition: Find the largest mountain in the array.
// * And remove the common element once as its added twice in both LIS and LDS.
int LongestBitonicSequence(vector<int> arr) {
        int n = arr.size();
        vector<int> dp1(n, 1), dp2(n, 1);

        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++) {
                if(arr[j] < arr[i] && dp1[i] < dp1[j] + 1)
                    dp1[i] = dp1[j] + 1;
            }
        }

        for(int i = n-1; i >= 0; i--){
            for(int j = n-1; j > i; j--) {
                if(arr[j] < arr[i] && dp2[i] < dp2[j] + 1)
                    dp2[i] = dp2[j] + 1;
            }
        }
        
        int maxi = 0;
        for(int i = 0; i < n; i++)
            maxi = max(maxi, dp1[i] + dp2[i] - 1);
        
        return maxi;
    }