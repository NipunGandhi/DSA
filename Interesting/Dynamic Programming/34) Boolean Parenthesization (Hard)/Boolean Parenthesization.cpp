#include <bits/stdc++.h>
using namespace std;

int mod = 1003;

class Solution{
public:
    int count(string& s, int i, int j, int isTrue,  vector<vector<vector<int>>>& dp){
        if(i > j) return 0;
        if(i == j){
            if(isTrue) return dp[i][j][isTrue] = s[i] == 'T';
            else return dp[i][j][isTrue] = s[i] == 'F';
        }
        
        if(dp[i][j][isTrue] != -1) return dp[i][j][isTrue];
        
        int ways = 0;
        
        for(int k = i + 1; k < j; k += 2){
            int lt = count(s, i , k - 1, 1, dp) % mod;
            int lf = count(s, i , k - 1, 0, dp) % mod;
            int rt = count(s, k + 1 , j, 1, dp) % mod;
            int rf = count(s, k + 1 , j, 0, dp) % mod;
            
            if(s[k] == '&'){
                if(isTrue) ways += ((lt * rt) % mod) % mod;
                else ways += ((lt * rf) % mod + (lf * rt) % mod + (lf * rf) % mod) % mod;
            }
            else if(s[k] == '|'){
                if(isTrue) ways += ((lt * rt) % mod + (lt * rf) % mod + (lf * rt) % mod) % mod;
                else ways += ((lf * rf) % mod) % mod;
            }
            else if(s[k] == '^'){
                if(isTrue) ways += ((lt * rf) % mod + (lf * rt) % mod) % mod;
                else ways += ((lt * rt) % mod + (lf * rf) % mod) % mod;
            }
        }
        
        return dp[i][j][isTrue] = ways % mod;
    }
    
    int countWays(int N, string S){
        vector<vector<vector<int>>> dp(N, vector<vector<int>>(N, vector<int>(2, -1)));
        return count(S, 0, N-1, 1, dp);
    }
};