class Solution {
public:
    void solver(int n,vector <string> &ans, string s, int i = 0, int j = 0 ){
      if(i==n && j==n){
          ans.push_back(s);
          return;
      }
      if(i + 1 <= n){
          s.push_back('(');
          solver(n,ans,s,i+1,j);
          s.pop_back();
      }

      if(j + 1 <=n && j+1 <= i){
          s.push_back(')');
          solver(n,ans,s,i,j+1);
          s.pop_back();
      }

    }

    vector<string> generateParenthesis(int n) {
        if(n==1) return {"()"};
        vector <string> ans;
        solver(n,ans,"");
        return ans;
    }
};