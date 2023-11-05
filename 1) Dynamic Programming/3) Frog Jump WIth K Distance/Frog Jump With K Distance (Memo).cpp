#include<bits/stdc++.h>
using namespace std;

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
    vector<int> memo(n,-1);
    return mem(n-1, k, height, memo);
}