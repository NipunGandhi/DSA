class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        if(n == 0) return true;
        stack<int> s1, s2;
        for(int i = 0; i < n; i++){
            char c = s[i];
            if(c == '(') s1.push(i);
            else if(c == '*') s2.push(i);
            else {
                if(s1.size() > 0) s1.pop();
                else if(s2.size() > 0) s2.pop();
                else return false;
            }
        }

        while(!s1.empty() && !s2.empty()){
            if(s1.top() > s2.top()) return false;
            s1.pop();
            s2.pop();
        }

        if(s1.size() > 0) return false;
        return true;
    }
};