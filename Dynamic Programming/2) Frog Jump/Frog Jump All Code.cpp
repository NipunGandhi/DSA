#include <bits/stdc++.h>
using namespace std;
int traverse(int n, vector<int> &heights){
    if(n == 0) return 0;
    int minus1 = traverse(n-1,heights) + abs(heights[n] - heights[n-1]);
    int minus2 = n>1 ? traverse(n-2, heights) + abs(heights[n] - heights[n-2]) : INT_MAX;
    return min(minus1, minus2);
} 

int memo(int n, vector<int> &heights, vector<int> &mem){
    if(n == 0) return 0;
    if(mem[n] != -1) return mem[n];
    int minus1 = traverse(n-1,heights) + abs(heights[n] - heights[n-1]);
    int minus2 = n>1 ? traverse(n-2, heights) + abs(heights[n] - heights[n-2]) : INT_MAX;
    return mem[n] = min(minus1, minus2);
} 

int frogJump(int n, vector<int> &heights)
{
    // return traverse(n-1,heights);
    // vector<int> mem(n,-1);
    // return memo(n-1,heights,mem); 
    vector<int> dp(n,0);
    dp[0] = 0;

    for(int i=1; i<n; i++){
        int minus1 = dp[i-1] + abs(heights[i] - heights[i-1]);
        int minus2 = i>1 ? dp[i-2] + abs(heights[i] - heights[i-2]) : INT_MAX;
        dp[i] = min(minus1, minus2);
    }
    return dp[n-1];
}