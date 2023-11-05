#include<bits/stdc++.h>
using namespace std;

int recursion(int n, int k, vector<int> &height){
    if(n==0) return 0;
    int ans = INT_MAX;
    for(int i=1; i<=k; i++){
        if(n-i >= 0){
            int val = recursion(n-i, k, height) + abs(height[n] - height[n-i]);
            ans = min(val,ans);
        } else{
            break;
        }
    }
    return ans;
}

int mem(int n, int k, vector<int> &height, vector<int> &memo){
    if(n==0) return 0;
    if(memo[n] != -1) return memo[n];
    int ans = INT_MAX;
    for(int i=1; i<=k; i++){
        if(n-i >= 0){
            int val = mem(n-i, k, height, memo) + abs(height[n] - height[n-i]);
            ans = min(val,ans);
        } else{
            break;
        }
    }
    return memo[n] = ans;
}

int minimizeCost(int n, int k, vector<int> &height){
    // return recursion(n-1,k,height);
    // vector<int> memo(n,-1);
    // return mem(n-1, k, height, memo);
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