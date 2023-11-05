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

int minimizeCost(int n, int k, vector<int> &height){
    return recursion(n-1,k,height);
}