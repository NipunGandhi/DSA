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
    int rob(vector<int>& nums) {
        return recursion(nums.size()-1, nums);
    }
};