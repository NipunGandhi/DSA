#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mem(int n, vector<int>& nums, vector<int> memo){
        if(n==0) return nums[n];
        if(n<0) return 0;
        if(memo[n] != -1) return memo[n];
        int picked = mem(n-2, nums, memo) + nums[n];
        int notpicked = mem(n-1, nums, memo) + 0;
        
        return memo[n] = max(picked,notpicked);
    }

    int rob(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);
        return mem(nums.size()-1, nums, memo);
    }
};