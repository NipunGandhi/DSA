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

    int solver(string& s, int start, vector<int>& dp){
        if(start == s.size()) return 0;
        if(dp[start] != -1) return dp[start];
        int ans = INT_MAX;
        for(int i = start; i < s.size(); i++){
            if(isPalindrome(s, start , i)){
                int temp = 1 + solver(s, i + 1, dp);
                ans = min(ans, temp);
            } 
        }
        return dp[start] = ans;
    }

    int minCut(string s) {
        vector<int> dp(s.size(), -1);
        return solver(s, 0, dp) - 1;
    }
};