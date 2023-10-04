class Solution {
public:
    string tree2str(TreeNode* root) {
        string ans;
        solve(root, ans);
        return ans;
    }

    void solve(TreeNode* root, string& ans){
        ans += to_string(root->val);
        if(root->left){
            ans += "(";
            solve(root->left, ans);
            ans += ")";
        }
        if(root->right){
            if(!root->left) ans += "()";
            ans += "(";
            solve(root->right, ans);
            ans += ")";
        }
    }
};