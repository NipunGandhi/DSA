class Solution {
public:
    bool recursive(string& s1, string& s2, string& s3, int i1, int i2, vector<vector<int>>& dp){
        bool choice1 = false;
        bool choice2 = false;
        if(i1 == 0 && i2 == 0) return 1;
        if(dp[i1][i2] != -1) return dp[i1][i2];

        if(i1 > 0 && s1[i1 - 1] == s3[(i1 + i2) - 1]){
            choice1 = recursive(s1, s2, s3, i1 - 1, i2, dp); 
        }
        if(i2 > 0 && s2[i2 - 1] == s3[(i1 + i2) - 1]){
            choice2 = recursive(s1, s2, s3, i1, i2 - 1, dp); 
        }

        return dp[i1][i2] = choice1 || choice2;
    }

    bool tab(string& s1, string& s2, string& s3){
        if(s1.size() + s2.size() != s3.size()) return false;
        vector<vector<int>> dp (s1.size() + 1, vector<int>(s2.size() + 1, 0));
        
        int i, j, z; 
        for (i = 0; i <= s1.size(); i++) {
            for (j = 0; j <= s2.size(); j++) {
                 if (i == 0 && j == 0) {
                    dp[i][j] = 1;
                    continue;
                }
                bool choice1 = false;
                bool choice2 = false;
                if (i > 0 && s1[i - 1] == s3[(i + j) - 1]) {
                    choice1 = dp[i - 1][j];
                }
                    
                if (j > 0 && s2[j - 1] == s3[(i + j) - 1]) {
                    choice2 = dp[i][j - 1];
                }
                dp[i][j] = choice1 || choice2;
            }
        }  
        return dp[i - 1][j - 1];
    }

    bool isInterleave(string s1, string s2, string s3) {
        // if(s1.size() + s2.size() != s3.size()) return false;
        // vector<vector<int>> dp (s1.size() + 1, vector<int>(s2.size() + 1, -1));
        // return recursive(s1, s2, s3, s1.size(), s2.size(), dp);
        return tab(s1, s2, s3);
    }
};