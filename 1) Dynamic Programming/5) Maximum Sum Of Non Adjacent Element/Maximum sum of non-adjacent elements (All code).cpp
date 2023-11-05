#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int recursion(int n, vector<int>& nums){
        if(n==0) return nums[n];
        if(n<0) return 0;

        int picked = recursion(n-2, nums) + nums[n];
        int notpicked = recursion(n-1, nums) + 0;
        
        return max(picked,notpicked);
    }

    int mem(int n, vector<int>& nums, vector<int> memo){
        if(n==0) return nums[n];
        if(n<0) return 0;
        if(memo[n] != -1) return memo[n];
        int picked = mem(n-2, nums, memo) + nums[n];
        int notpicked = mem(n-1, nums, memo) + 0;
        
        return memo[n] = max(picked,notpicked);
    }

    int tab(int n,vector<int>& nums){
        if(n== 1) return nums[0];
        vector<int> dp(n, -1);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i<n; i++){
            int picked = dp[i-2] + nums[i];
            int notpicked = dp[i-1] + 0;
            dp[i] = max(picked,notpicked);
        }
        return dp[n-1];
    }

    int space(int n,vector<int>& nums){
        if(n== 1) return nums[0];
        int prev2 = nums[0];
        int prev1 = max(nums[0], nums[1]);
        for(int i = 2; i<n; i++){
            int picked = prev2 + nums[i];
            int notpicked = prev1 + 0;
            prev2 = prev1;
            prev1 = max(picked,notpicked);
        }
        return prev1;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        // return recursion(nums.size()-1, nums);
        // vector<int> memo(nums.size(), -1);
        // return mem(nums.size()-1, nums, memo);
        // return tab(n, nums);
        return space(n,nums);
    }
};