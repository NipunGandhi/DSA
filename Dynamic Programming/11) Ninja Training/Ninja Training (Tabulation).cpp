int tabular(int n, vector<vector<int>> &points){
    vector<vector <int>> dp(n, vector <int>(4,0));
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

    for(int i = 1; i < n; i++){
        for(int j = 0; j < 4; j++){
            dp[i][j] = 0;
            for(int x=0; x<3; x++){
                if(x!=j){
                    int val = points[i][x] + dp[i-1][x];
                    dp[i][j] = max(dp[i][j], val); 
                } 
            }
        }
    }
    return dp[n-1][3];
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    return tabular(n, points);
}