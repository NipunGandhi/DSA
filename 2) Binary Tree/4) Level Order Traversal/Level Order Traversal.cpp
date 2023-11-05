class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int level = q.front().second;
            q.pop();
            if(ans.size() == level) ans.push_back({node->val});
            else ans[level].push_back(node->val);
            if(node->left != NULL) q.push({node->left, level + 1});
            if(node->right != NULL) q.push({node->right, level + 1}); 
        }
        return ans;
    }
};