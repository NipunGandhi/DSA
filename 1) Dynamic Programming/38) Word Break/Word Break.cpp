class Solution {
public:
    bool recursion(unordered_set<string>& set, string s, int index, unordered_map<string, int>& dp){
        if(s.size() == 0) return true;
        if(index == 0) return false;
        string key = s + " " + to_string(index);
        if(dp.find(key) != dp.end()) return dp[key];

        while(index > 0){
            string temp = s.substr(index - 1);
            if(set.find(temp) != set.end()){
                bool ans = recursion(set, s.substr(0, index - 1), index - 1, dp);
                if(ans) return dp[key] = true;
            }
            index--;
        }

        return dp[key] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set;
        for(auto i: wordDict){
            set.insert(i);
        }
        unordered_map<string, int> dp;
        return recursion(set, s, s.size(), dp); 
    }
};