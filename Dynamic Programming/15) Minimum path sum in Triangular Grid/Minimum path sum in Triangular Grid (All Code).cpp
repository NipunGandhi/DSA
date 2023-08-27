class Solution {
public:
    int recursion(int i, int j, vector<vector<int>>& triangle) {
        if(i == triangle.size()-1){
            return triangle[i][j];
        }
        int bottom = triangle[i][j] + recursion(i+1, j, triangle);
        int bottomRight = triangle[i][j] + recursion(i+1, j+1, triangle);
        return min(bottom, bottomRight);        
    }

    int tab(int n, vector<vector<int>>& triangle){
        vector<vector<int>> dp(n, vector<int> (n, INT_MAX));

        for(int i=n-1; i>=0;i--){
            for(int j = triangle[i].size()-1; j>=0; j--){
                if(i == n-1){
                    dp[n-1][j] = triangle[n-1][j];
                    continue;   
                } 
                int bottom = triangle[i][j] + dp[i+1][j];
                int bottomRight = triangle[i][j] + dp[i+1][j+1];
                dp[i][j] = min(bottom, bottomRight);        
            }
        }
        return dp[0][0];
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        // return recursion(0, 0,triangle);
        // vector<vector<int>> dp(n, vector<int> (n+1,INT_MAX));
        // return memo(n-1, n, triangle, dp);
        return tab(n, triangle);
    }
};