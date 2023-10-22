class Solution {
  public:
    int occurence(int n, int target, vector<int>& nums, vector<vector<int>>& memo){
        if(n == 0) return target == 0;
        if(target < 0) return 0;
        if(memo[n][target] != -1) return memo[n][target] % 1000000007;
        memo[n][target] = occurence(n - 1, target - nums[n-1], nums, memo) + occurence(n - 1, target, nums, memo);
        return memo[n][target] % 1000000007;
    }
  
    int countPartitions(int n, int target, vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < n; i++) sum += nums[i];
        if((sum + target) % 2 != 0) return 0;
        int s1 = (sum + target) / 2;
        // vector<vector<int>> memo (n + 1, vector<int>(s1 + 1, -1));
        // return occurence(n, s1, nums, memo);
        vector<vector<int>> dp (n + 1, vector<int>(s1 + 1, 0));
        dp[0][0] = 1;
        
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= s1; j++){
                 if(j - nums[i-1] >= 0) dp[i][j] = dp[i - 1][j - nums[i-1]] + dp[i - 1][j];
                 else dp[i][j] = dp[i - 1][j];
                 dp[i][j] %= 1000000007;
            }
        }
        
        return dp[n][s1];
    }
};
