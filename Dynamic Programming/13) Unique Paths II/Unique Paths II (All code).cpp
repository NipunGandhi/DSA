class Solution {
public:
    int traverse(int m, int n, vector<vector<int>>& obstacleGrid){
        if(m < 0 || n < 0 || obstacleGrid[m][n] == 1) return 0;
        if(m==0 && n==0) return 1;
        int top = traverse(m-1,n,obstacleGrid);
        int left = traverse(m,n-1,obstacleGrid);
        return top+left;
    }

    int memo(int m, int n, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp){
        if(m < 0 || n < 0 || obstacleGrid[m][n] == 1) return 0;
        if(m==0 && n==0) return 1;
        if(dp[m][n] != -1) return dp[m][n];
        int top = memo(m-1,n,obstacleGrid,dp);
        int left = memo(m,n-1,obstacleGrid,dp);
        return dp[m][n] = top+left;
    }

    int tab(int m, int n, vector<vector<int>> obstacleGrid){
        vector<vector<int>> dp(m, vector<int>(n,0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n;j++){
                if(obstacleGrid[i][j] == 1) dp[i][j] = 0;
                else if (i == 0 && j == 0) dp[i][j] = 1;
                else {
                    int top = i-1 >= 0? dp[i-1][j]:0;
                    int left = j-1 >= 0? dp[i][j-1]:0;
                    dp[i][j] = top + left;
                }
            }
        }
        return dp[m-1][n-1];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[n].size();
        // return traverse(m-1, n-1, obstacleGrid);
        // vector<vector<int>> dp(m, vector<int>(n,-1));
        // return memo(m-1, n-1, obstacleGrid, dp);
        return tab(m,n,obstacleGrid);
    }
};