class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans;
        for(int i = 0; i < expression.size(); i++){
            char c = expression[i];
            if(c == '+' || c == '-' || c == '*'){
                //prefix
                vector<int> pre = diffWaysToCompute(expression.substr(0,i));
                //postfix
                vector<int> post = diffWaysToCompute(expression.substr(i+1));
                for(auto n1: pre){
                    for(auto n2:post){
                        if(c == '+') ans.push_back(n1+n2);
                        else if(c == '*') ans.push_back(n1*n2);
                        else if(c == '-') ans.push_back(n1-n2);
                    }
                }
            }
        }
        if(ans.size()==0) ans.push_back(atoi(expression.c_str()));
        return ans;
    }
};