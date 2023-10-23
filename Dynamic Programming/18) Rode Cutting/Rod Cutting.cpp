class Solution{
  public:
    int cost(int price[], int lengthOfRod, int index,  vector<vector<int>>& memo){
        if(lengthOfRod <= 0 || index <= 0) return 0;
        if(memo[index][lengthOfRod] != -1) return memo[index][lengthOfRod];
        
        int pick = price[index - 1] + cost(price, lengthOfRod - index, index, memo);
        int notPick = cost(price, lengthOfRod, index - 1, memo);
        
        return memo[index][lengthOfRod] = max(pick, notPick);
    }
    
    int cutRod(int price[], int n) {
        // vector<vector<int>> memo (n + 1,vector<int>(n + 1, -1));  
        // return cost(price, n, n, memo);
        vector<vector<int>> memo (n + 1,vector<int>(n + 1, 0));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(j - i >= 0){
                    int pick = price[i - 1] + memo[i][j - i];  
                    int notPick = memo[i - 1][j];
                    memo[i][j] = max(pick, notPick);
                } else {
                    memo[i][j] = memo[i - 1][j];
                }
            }
        }
        
        return memo[n][n]; 
    }
};