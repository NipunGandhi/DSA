#include<bits/stdc++.h>
using namespace std;

int recursive(int days, int lastTask, vector<vector<int>> &points){
    if(days == 0){
        int maximum = INT_MIN;
        for(int i=0; i<3; i++){
            if(i!= lastTask) maximum = max(maximum, points[days][i]); 
        }
        return maximum;
    }

    int maximum = INT_MIN;

    for(int i = 0; i < 3; i++){
        if(i != lastTask) {
            int val = points[days][i] + recursive(days-1, i, points);
            maximum = max(maximum, val); 
        }
    }
    return maximum;
}

int mem(int days, int lastTask, vector<vector<int>> &points, vector<vector<int>> memo){
    if(days == 0){
        int maximum = INT_MIN;
        for(int i=0; i<3; i++){
            if(i!= lastTask) maximum = max(maximum, points[days][i]); 
        }
        return maximum;
    }
    if(memo[days][lastTask] != -1) return memo[days][lastTask];
    int maximum = INT_MIN;

    for(int i = 0; i < 3; i++){
        if(i != lastTask) {
            int val = points[days][i] + mem(days-1, i, points, memo);
            maximum = max(maximum, val); 
        }
    }
    return memo[days][lastTask] = maximum;
}

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
    // return recursive(n-1, 3, points);
    // vector<vector <int>> memo(n, vector <int>(4,-1));
    // return mem(n-1, 3, points, memo);
    return tabular(n, points);
}


