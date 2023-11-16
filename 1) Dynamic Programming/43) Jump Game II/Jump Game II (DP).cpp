class Solution {
public:
    int recursive(vector<int>& nums, int index, vector<int>& memo){
        if(index == nums.size() - 1) return 0;
        if(index >= nums.size()) return INT_MAX - 1;
        if(memo[index] != -1) return memo[index];
        int maxJumps = nums[index];
        int ans = INT_MAX - 1;

        for(int i = 1; i <= maxJumps; i++){
            ans = min(ans, recursive(nums, index + i, memo));
        }

        return memo[index] = ans + 1;
    }

    int jump(vector<int>& nums) {
        // vector<int> memo(nums.size(), -1);
        // return recursive(nums, 0, memo);  
        vector<int> memo(nums.size(), INT_MAX - 1); 
        memo[nums.size() - 1] = 0;
        for(int index = nums.size() - 2; index >= 0; index--){
            int maxJumps = nums[index];
            int ans = INT_MAX - 1;

            for(int i = 1; i <= maxJumps; i++){
                if(index + i < nums.size()) ans = min(ans, memo[index + i]);
                else break;
            }

            memo[index] = ans + 1;
        }
        return memo[0];
    }
};