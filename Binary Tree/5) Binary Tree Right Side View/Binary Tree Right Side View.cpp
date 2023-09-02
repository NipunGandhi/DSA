class Solution {
public:
    void dfs(TreeNode* root, vector<int>& ans, int level){
        if(root == NULL) return;
        if(level+1 > ans.size()) ans.push_back(0);
        ans[level] = root->val;
        dfs(root->left, ans, level+1);
        dfs(root->right, ans, level+1);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        dfs(root,ans,0);
        return ans;
    }
};