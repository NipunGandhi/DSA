class Solution {
public:
    int recursive(int m, int n, vector<vector<int>>& grid){
        if(m==0 && n==0) return grid[m][n];

        int top = m-1>=0? grid[m][n] + recursive(m-1, n , grid) : INT_MAX;
        int left = n-1>=0? grid[m][n] + recursive(m, n-1 , grid) : INT_MAX;

        return min(top,left);
    }

    int mem(int m, int n, vector<vector<int>>& grid,vector<vector<int>> dp){
        if(m==0 && n==0) return grid[m][n];
        if(dp[m][n] != -1) return dp[m][n];

        int top = m-1>=0? grid[m][n] + mem(m-1, n , grid, dp) : INT_MAX;
        int left = n-1>=0? grid[m][n] + mem(m, n-1 , grid, dp) : INT_MAX;

        return dp[m][n] = min(top,left);
    }

    int tab(int m, int n, vector<vector<int>>& grid,vector<vector<int>> dp){
        dp[0][0] = grid[0][0];
        for(int i=0; i<=m; i++){
            for(int j=0; j<=n;j++){
                if(i==0 && j == 0){
                    dp[0][0] = grid[0][0];
                    continue;
                }
                int top = i-1>=0? grid[i][j] + dp[i-1][j] : INT_MAX;
                int left = j-1>=0? grid[i][j] + dp[i][j-1] : INT_MAX;
                dp[i][j] = min(top,left);
            }
        }

        return dp[m][n];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // return recursive(m-1,n-1,grid);
        // vector<vector<int>> dp(m, vector<int> (n,-1));
        // return mem(m-1,n-1,grid, dp);
        vector<vector<int>> dp(m, vector<int> (n,0));
        return tab(m-1,n-1,grid,dp);
    }
};