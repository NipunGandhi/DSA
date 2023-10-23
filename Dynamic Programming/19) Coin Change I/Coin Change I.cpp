class Solution {
public:
    int recursive(vector<int>& coins, int amount, int index, vector<vector<int>>& memo){
        if(amount == 0) return 0;
        if(index == 0 || amount < 0) return INT_MAX;
        if(memo[index][amount] != -1) return memo[index][amount];
        
        int pick = recursive(coins, amount - coins[index - 1], index, memo);
        int notPick = recursive(coins, amount, index - 1, memo);
        
        if(pick == notPick && pick == INT_MAX) return memo[index][amount] = INT_MAX;
        if(pick == INT_MAX) return memo[index][amount] = notPick;
        else return memo[index][amount] = min(1 + pick, notPick);
    }
    int coinChange(vector<int>& coins, int amount) {
        // vector<vector<int>> memo(coins.size() + 1, vector<int>(amount + 1, -1));
        // int ans = recursive(coins, amount, coins.size(), memo);
        // if(ans == INT_MAX) return -1;
        // return ans;
        vector<vector<int>> memo(coins.size() + 1, vector<int>(amount + 1, INT_MAX));
        int n = coins.size();
        for(int i = 0; i <= n; i++) memo[i][0] = 0;
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= amount; j++){
                int pick = INT_MAX;
                if(j - coins[i - 1] >= 0) pick = memo[i][j - coins[i - 1]];
                int notPick = memo[i - 1][j];
                
                if(pick == notPick && pick == INT_MAX) memo[i][j] = INT_MAX;
                else if(pick == INT_MAX) memo[i][j] = notPick;
                else memo[i][j] = min(1 + pick, notPick);
            }
        }
        if(memo[n][amount] == INT_MAX) return -1;
        return memo[n][amount];
    }
};