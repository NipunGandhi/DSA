#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i<nums.size(); i++){
            int picked = dp[i-2] + nums[i];
            int notpicked = dp[i-1] + 0;
            dp[i] = max(picked,notpicked);
        }
        return dp[nums.size()-1];
    }
};