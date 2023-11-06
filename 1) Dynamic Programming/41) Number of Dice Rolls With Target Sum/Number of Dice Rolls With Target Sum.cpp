class Solution {
public:
    int mod = 1e9 + 7;
    int recursion(int n, int k, int target, vector<vector<int>>& memo){
        if(n == 1) return target <= k && target > 0; 
        if(n == 0 || target <= 0) return 0;
        if(memo[n][target] != -1) return memo[n][target];
        long long ans = 0; 
        for(int i = 1; i <= min(target, k); i++){
            ans += recursion(n - 1, k, target - i, memo) % mod; 
        }
        return memo[n][target] = ans % mod;
    }

    int numRollsToTarget(int n, int k, int target) {
        // vector<vector<int>> memo(n+1, vector<int>(target+1, -1));
        // return recursion(n, k, target, memo);
        vector<vector<int>> memo(n + 1, vector<int>(target + 1, 0));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= target; j++){
                long long ans = 0; 
                if(i == 1){
                    memo[i][j] = (j <= k && j > 0);
                    continue;
                }
                for(int x = 1; x <= min(j, k); x++){
                    if(j - x >= 0) ans += memo[i - 1][j - x] % mod; 
                }
                memo[i][j] = ans % mod;
            }
        }
        return memo[n][target];
    }
};