class Solution {
public:
    long long recursive(int candies, int& limit, int child, vector<vector<int>>& memo) {
        if(candies == 0 && child == 0) return 1;
        if(child == 0 || candies < 0) return 0;
        if(memo[candies][child] != -1) return memo[candies][child];
            
        long long ans = 0;
        for(int i = 0; i <= limit; i++){
            ans += recursive(candies - i, limit, child - 1, memo);
        }
         
        return memo[candies][child] = ans;
    }
    
    int distributeCandies(int n, int limit) {
        // vector<vector<int>> memo(n + 1, vector<int>(4, -1));
        // return recursive(n, limit, 3, memo);
        vector<vector<long long>> memo(n + 1, vector<long long>(4, 0));
        memo[0][0] = 1;            
        for(int i = 0; i <= n; i++){
            for(int j = 1; j <= 3; j++){
                long long ans = 0;
                for(int x = 0; x <= limit; x++){
                    if(i - x >= 0) {
                        ans += memo[i - x][j - 1];
                    }
                }
                memo[i][j] = ans;
            }
        }
        return memo[n][3];

    }
};