class Solution {
public:
    int recursiveWays(string& s, int i, vector<int>& memo){
        if(i == 1 && s[i - 1] != '0') return 1;
        if(i == 0) return 1;
        if(memo[i] != -1) return memo[i];
        
        int jump1 = 0, jump2 =  0;
        if(s[i - 1] != '0') jump1 = recursiveWays(s, i - 1, memo);
        if(i - 2 >= 0 && s[i - 2] == '1') jump2 = recursiveWays(s, i - 2, memo);
        else if(i - 2 >= 0 && s[i - 2] == '2' && s[i - 1] - '0' <= 6) jump2 = recursiveWays(s, i - 2, memo);
        
        return memo[i] = jump1 + jump2;
    }

    int numDecodings(string s) {
        // if(s[0] == '0') return 0;
        // vector<int> memo (s.size() + 1, -1);
        // return recursiveWays(s, s.size(), memo);
        vector<int> memo (s.size() + 1, 0);
        int n = s.size();
        memo[0] = 1;
        if(s[0] != '0') memo[1] = 1;
        
        for(int i = 2; i <= n; i++){
            int jump1 = 0, jump2 =  0;
            if(s[i - 1] != '0') jump1 = memo[i - 1];
            if(i - 2 >= 0 && s[i - 2] == '1') jump2 = memo[i - 2];
            else if(i - 2 >= 0 && s[i - 2] == '2' && s[i - 1] - '0' <= 6) jump2 = memo[i-2];
            memo[i] = jump1 + jump2;
        }

        return memo[n];
    }
};