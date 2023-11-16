class Solution {
public:
    bool recursive(vector<int>& nums, int index, vector<int>& memo){
        if(index == nums.size() - 1) return true;
        if(index >= nums.size()) return false;
        if(memo[index] != -1) return memo[index];

        int maxJump = nums[index];
        bool ans = false;
        for(int i = 1; i <= maxJump; i++){
            if(index + i < nums.size()) ans |= recursive(nums, index + i, memo); 
            else break;
        }

        return memo[index] = ans;
    }
    
    bool canJump(vector<int>& nums) {
        // vector<int> memo(nums.size(), -1);
        // return recursive(nums, 0, memo);
        int n = nums.size();
        if (n == 0) return false;

        vector<int> memo(n, 0);
        memo[n - 1] = 1;

        for (int index = n - 2; index >= 0; index--) {
            int maxJump = nums[index];
            bool ans = false;
            for (int i = 1; i <= maxJump; i++) {
                if(index + i < nums.size()) ans |= memo[index + i]; 
                else break;
            }
            memo[index] = ans;
        }
        return memo[0];
    }
};