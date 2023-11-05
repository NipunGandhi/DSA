class Solution {
public:
    void traverse(TreeNode* root, vector<int>& ans, int level){
      if(root == NULL) return;
      if(ans.size() == level){
        ans.push_back(root->val);
      } else ans[level] = root->val;
      traverse(root->left, ans, level+1);
      traverse(root->right, ans, level+1);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        traverse(root, ans, 0);
        return ans;
    }
};