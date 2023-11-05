class Solution {
public:
    int recursive(string& text1, string& text2, int t1, int t2, vector<vector<int>>& memo){
        if(t1 == 0 || t2 == 0) return 0;
        if(memo[t1][t2] != -1) return memo[t1][t2];
        if(text1[t1 - 1] == text2[t2 - 1]){
            return memo[t1][t2] = 1 + recursive(text1, text2, t1-1, t2-1, memo);
        } else {
            return memo[t1][t2] = max(recursive(text1, text2, t1, t2 - 1, memo), recursive(text1, text2, t1 - 1, t2, memo));
        } 
    }

    int longestCommonSubsequence(string text1, string text2) {
        // vector<vector<int>> memo(text1.size() + 1, vector(text2.size() + 1, -1));
        // return recursive(text1, text2, text1.size(), text2.size(), memo); 

        vector<vector<int>> memo(text1.size() + 1, vector(text2.size() + 1, 0));
        for(int i = 1; i <= text1.size(); i++){
            for(int j = 1; j <= text2.size(); j++){
                if(text1[i - 1] == text2[j - 1]){
                    memo[i][j] = 1 + memo[i-1][j-1];
                } else {
                    memo[i][j] = max(memo[i][j - 1], memo[i - 1][j]);
                } 
            }
        }

        return memo[text1.size()][text2.size()];
    }
};