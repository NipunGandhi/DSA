class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>> memo (n + 1, vector<int>(m + 1, 0));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(str1[i-1] == str2[j-1]) memo[i][j] = 1 + memo[i-1][j-1];
                else memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
            }
        }
        int subsequenceLength = memo[n][m];
        string ans = "";
        for(int i = 0; i < subsequenceLength; i++) ans += '$';
        while(n > 0 && m > 0){
            if(str1[n-1] == str2[m-1]){
                ans[subsequenceLength-1] = str1[n-1];
                n--; m--; subsequenceLength--;
            } else if (memo[n-1][m] > memo[n][m-1]){
                n--;
            } else {
                m--;
            }
        }
        
        n = 0, m = 0; int i = 0; 
        string newAns = "";
        while(n < str1.size() && m < str2.size() && i < ans.size()){
            if(str1[n] == ans[i] && str2[m] == ans[i]){
                newAns += ans[i];
                i++;
                n++;
                m++;
            } else if(str1[n] != ans[i]){
                newAns += str1[n];
                n++;
            } else if(str2[m] != ans[i]){
                newAns += str2[m];
                m++;
            }
        }
        return newAns + str1.substr(n) + str2.substr(m);      
    }
};