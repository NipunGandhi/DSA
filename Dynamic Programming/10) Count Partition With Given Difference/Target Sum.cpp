class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0; int n = nums.size();
        for(int i = 0; i < n; i++) sum += nums[i];
        if((sum + target) % 2 != 0) return 0;
        int s1 = (sum + target) / 2;
        if(s1 < 0) return false;
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