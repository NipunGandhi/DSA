class Solution {
public:
    int minChanges(string s) {
        int count = 0;
        for(int i = 1; i < s.size(); i++){
            if(s[i] != s[i-1] && i % 2 != 0){
                count++;
            }
        }
        return count;
    }
};