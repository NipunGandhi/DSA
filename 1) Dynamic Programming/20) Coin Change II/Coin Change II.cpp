class Solution {
public:
    int recursive(int index, int amount, vector<int>& coins, vector<vector<int>>& memo){
        if(amount == 0) return 1;
        if(index == 0 || amount <= 0) return 0;
        if(memo[index][amount] != -1) return memo[index][amount];

        int pick = recursive(index, amount - coins[index - 1], coins, memo);
        int notPick =  recursive(index - 1, amount, coins, memo);
        return memo[index][amount] = pick + notPick;
    }

    int change(int amount, vector<int>& coins) {
        // vector<vector<int>> memo(coins.size() + 1, vector<int>(amount + 1, -1));
        // return recursive(coins.size(), amount, coins, memo);
        vector<vector<int>> memo(coins.size() + 1, vector<int>(amount + 1, 0));
        for(int i = 0; i <= coins.size(); i++){
            memo[i][0] = 1;
        }

        for(int i = 1; i <= coins.size(); i++){
            for(int j = 1; j <= amount; j++){
                int pick = 0;
                if(j - coins[i - 1] >= 0) pick = memo[i][j - coins[i - 1]];
                int notPick = memo[i - 1][j];
                memo[i][j] = pick + notPick;
            }
        }

        return memo[coins.size()][amount];
    }
};