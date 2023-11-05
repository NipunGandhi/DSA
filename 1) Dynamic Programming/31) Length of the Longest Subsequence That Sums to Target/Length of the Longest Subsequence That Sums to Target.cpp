class Solution {
public
    int recursive(vectorint& nums, int target, int index, vectorvectorint& memo){
        if(target == 0) return 0;
        if(target  0  index == 0) return INT_MIN + 1;
        if(memo[index][target] != -1) return memo[index][target];
        int pick = 1 + recursive(nums, target - nums[index-1], index-1, memo);
        int notPick = recursive(nums, target, index-1, memo);
        return memo[index][target] = max(notPick, pick);
    }

    int lengthOfLongestSubsequence(vectorint& nums, int target) {
        // vectorvectorint memo (nums.size() + 1, vectorint (target + 1, -1)); 
        // int ans = recursive(nums, target, nums.size(), memo);
        vectorvectorint memo (nums.size() + 1, vectorint (target + 1, INT_MIN+1));
        for(int i = 0; i  nums.size(); i++) memo[i][0] = 0;
        for(int i = 1; i = nums.size(); i++){
            for(int j = 1; j = target; j++){
                int pick = INT_MIN + 1;
                if(j-nums[i-1] = 0) pick = 1 + memo[i-1][j-nums[i-1]];
                int notPick = memo[i-1][j];
                memo[i][j] = max(notPick, pick);
            }
        } 
        int ans = memo[nums.size()][target];
        if(ans  0) return -1;
        else return ans;
    }
};