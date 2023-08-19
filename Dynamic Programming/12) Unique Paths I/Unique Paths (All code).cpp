class Solution {
public:
    int traverse(int m, int n){
        if(m==0 && n==0) return 1;
        if(m < 0 || n < 0) return 0;

        int goTop = traverse(m-1,n);
        int goLeft = traverse(m,n-1);

        return goTop + goLeft;
    }

    int mem(int m, int n, vector<vector<int>> dp){
        if(m==0 && n==0) return 1;
        if(m < 0 || n < 0) return 0;
        if(dp[m][n] != -1) return dp[m][n];
        int goTop = traverse(m-1,n);
        int goLeft = traverse(m,n-1);

        return dp[m][n] = goTop + goLeft;
    }

    int uniquePaths(int m, int n) {
        // return traverse(m-1,n-1);
        // vector<vector<int>> dp(m,vector<int> (n,-1));
        // return mem(m-1,n-1, dp);
        vector<vector<int>> dp(m,vector<int> (n,0));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i == 0 && j == 0) dp[i][j] = 1;
                else {
                    int goTop = i - 1 >= 0 ? dp[i - 1][j] : 0;
                    int goLeft = j - 1 >= 0 ? dp[i][j - 1] : 0;
                    dp[i][j] = goTop + goLeft;
                }
            }
        }
        return dp[m-1][n-1];
    }
};