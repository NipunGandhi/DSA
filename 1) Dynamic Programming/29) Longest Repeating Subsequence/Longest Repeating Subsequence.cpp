#include<bits/stdc++.h>
using namespace std;
class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		    string s = str;
		    int n = s.size();
		    vector<vector<int>> memo (n + 1, vector<int>(n + 1, 0));
		    for(int i = 1; i <= n; i++){
		        for(int j = 1; j <= n; j++){
		            if(s[i-1] == str[j-1] && i != j) memo[i][j] = 1 + memo[i-1][j-1];
                    else memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
		        }
		    }
		    return memo[n][n];
		}

};
