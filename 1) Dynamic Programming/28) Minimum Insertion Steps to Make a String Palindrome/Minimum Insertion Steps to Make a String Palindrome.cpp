class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        string str = s;  
        reverse(s.begin(), s.end());
        vector<vector<int>> memo (n + 1, vector<int>(n + 1, 0));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(s[i-1] == str[j-1]) memo[i][j] = 1 + memo[i-1][j-1];
                else memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
            }
        }
        return n - memo[n][n];
    }
};