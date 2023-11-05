#include<bits/stdc++.h>
using namespace std;
class Solution
{
    private:
    int tab(int W, int wt[], int val[], int n){
        vector<vector<int>> memo(n + 1, vector<int>(W + 1, 0));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= W; j++){
                int pick = 0;
                if(wt[i-1] <= j){
                    pick = val[i-1] + memo[i-1][j - wt[i-1]];
                }
                
                int notPick = memo[i-1][j];
                memo[i][j] = max(pick, notPick);
            }
        }
        return memo[n][W];
    }
    
    int recursive(int W, int wt[], int val[], int n, vector<vector<int>> &memo){
        if(W <= 0 || n < 0) return 0;
        if(memo[n][W] != -1) return memo[n][W];
        int pick = 0;
        if(wt[n] <= W) {
            pick = val[n] + recursive(W - wt[n], wt, val, n-1, memo);
        }
        int notPick = recursive(W, wt, val, n-1, memo);
        return memo[n][W] = max(pick, notPick);
    }
    
    public:
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        // vector<vector<int>> memo(n, vector<int>(W + 1,-1));
        // return recursive(W, wt, val, n-1, memo);
        return tab(W, wt, val, n);
    }
};
