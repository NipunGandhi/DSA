class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return {};
        vector<vector<int>> ans;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});

        while(!q.empty()){
            TreeNode* element = q.front().first;
            int level = q.front().second;
            q.pop();

            if (level >= ans.size()) ans.push_back(vector<int>());
            ans[level].push_back(element->val);
            
            if(element->left != nullptr){
                q.push({element->left,level+1});
            }
            if(element->right != nullptr){
                q.push({element->right,level+1});
            }
        }
        return ans;
    }
};