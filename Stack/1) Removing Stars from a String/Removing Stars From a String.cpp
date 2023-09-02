class Solution {
public:
    string removeStars(string s) {
        string ans;
        stack <int> stack;
        int count = 0;
        for(int i = s.size() - 1; i >= 0; i--){
            if(s[i] == '*') count++;
            else if(count) {
                count--;
            } else {
                stack.push(s[i]);
            }
        } 
        while(!stack.empty()){
            ans.push_back(stack.top());
            stack.pop();
        }
        return ans;  
    }
};