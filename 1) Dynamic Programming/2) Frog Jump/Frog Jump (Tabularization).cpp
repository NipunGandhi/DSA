int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n, 0);
    dp[0] = 0;
    for(int i=1; i<n; i++){
        int minus1 = dp[i-1] + abs(heights[i] - heights[i-1]);
        int minus2 = i > 1 ? dp[i-2] + abs(heights[i] - heights[i-2]): INT_MAX;
        dp[i] = min(minus1,minus2);
    }
    return dp[n-1];
}