class Solution {
public:
    bool recursion(int size, int sum, vector<int>& nums, vector<vector<int>> &memo){
        if(sum == 0) return true;
        if(sum < 0 || size == 0) return false;
        if(memo[size][sum] != -1) return memo[size][sum];
        
        return memo[size][sum] = recursion(size - 1, sum - nums[size - 1], nums, memo) || recursion(size - 1, sum, nums, memo);
    }

    bool tab(vector<int>& nums, int sum){
        vector<vector<int>> memo(nums.size() + 1, vector<int>(sum + 1, 0));
        for(int i = 0; i <= nums.size(); i++){
            memo[i][0] = true;
        }

        for(int i = 1; i <= nums.size(); i++){
            for(int j = 1; j <= sum; j++){               
                if(j - nums[i - 1] < 0) memo[i][j] = memo[i - 1][j];
                else memo[i][j] = memo[i - 1][j - nums[i - 1]] || memo[i - 1][j];
            }
        }
 
        return memo[nums.size()][sum];
    }
    
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto i:nums) sum += i;
        if(sum & 1 == 1) return false;
        // vector<vector<int>> memo(nums.size() + 1, vector<int>(sum + 1 , -1));
        // return recursion(nums.size(), sum/2,  nums, memo);
        return tab(nums, sum/2);
    }
};