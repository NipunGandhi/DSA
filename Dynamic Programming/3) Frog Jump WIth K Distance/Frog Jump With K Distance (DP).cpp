#include<bits/stdc++.h>
using namespace std;

int minimizeCost(int n, int k, vector<int> &height){
    vector<int> dp(n,0);
    for(int i = 1; i < n; i++){
        int ans = INT_MAX;

        for(int j=1; j<=k; j++){
            if(i-j >= 0){
            int val = dp[i-j] + abs(height[i] - height[i-j]);
            ans = min(val,ans);
            }
        }
        dp[i] = ans;
    }
    return dp[n-1];
}