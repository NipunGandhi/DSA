class Solution {
public:
    bool isSubsequence(string s, string t) {
      int count = s.size();
      int j = 0;
      for(int i =0; i<t.size();i++){
        if(t[i] == s[j]){
          count--;
          j++;
        } 
        if(count == 0)return true;
      }
      return s==t;
    }
};