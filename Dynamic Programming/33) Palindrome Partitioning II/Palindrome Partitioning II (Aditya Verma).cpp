class Solution {
public:
    bool isPalindrome(string& s, int i, int j){
        if(i == j) return true;
        while(i <= j){
            if(s[i] != s[j]) return false;
            i++; j--;
        }
        return true;
    }

    int solver(string& s, int start, int end, vector<vector<int>>& dp){
        if(start >= end) return dp[start][end] = 0;
        if(dp[start][end] != -1) return dp[start][end];
        int ans = INT_MAX;
        if(isPalindrome(s, start , end)) return dp[start][end] = 0;
        for(int i = start; i < end; i++){
            int temp = solver(s, start, i, dp) + solver(s, i + 1, end, dp) + 1;
            ans = min(ans, temp);
        }
        return dp[start][end] = ans;
    }

    int minCut(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        return solver(s, 0, s.size() - 1, dp);     
    }
};