#include<bits/stdc++.h>
using namespace std;

// * TC: O(n^2)
// * SC: O(n)
// * Intuition: Find the largest mountain in the array.
// * And figure out how you will get the remaining elements after removing the mountain from the array.
int minimumMountainRemovals(vector<int>& nums) {
    int n = nums.size();
    vector<int> LIS(n, 1), LDS(n, 1);

    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++) {
            if(nums[j] < nums[i] && LIS[i] < LIS[j] + 1)
                LIS[i] = LIS[j] + 1;
        }
    }

    for(int i = n-1; i >= 0; i--){
        for(int j = n-1; j > i; j--) {
            if(nums[j] < nums[i] && LDS[i] < LDS[j] + 1)
                LDS[i] = LDS[j] + 1;
        }
    }
    
    int maxi = 0;
    for(int i = 0; i < n; i++){
        if(LIS[i] > 1 && LDS[i] > 1)
        maxi = max(maxi, LIS[i] + LDS[i] - 1);
    }
    
    return n - maxi;
}