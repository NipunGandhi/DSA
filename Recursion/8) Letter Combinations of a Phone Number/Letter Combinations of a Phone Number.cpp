class Solution {
public:
    unordered_map<char, string> keys = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    void solver(string digits, int index, string temp, vector<string>& ans){
        if(temp.size() == digits.size()){
            ans.push_back(temp);
            return;
        }
        for(auto i: keys[digits[index]]){
            temp.push_back(i);
            solver(digits, index+1, temp, ans);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        vector<string> ans;
        solver(digits, 0, "", ans);
        return ans;
    }
};