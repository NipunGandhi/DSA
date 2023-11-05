class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        if(root->left == NULL && root->right == NULL) return root->val;
        queue<TreeNode*> q;
        int ans;
        q.push(root);

        while(!q.empty()){
            TreeNode* element = q.front();
            q.pop();
            ans = element->val;
            if(element->right != NULL) q.push(element->right);
            if(element->left != NULL) q.push(element->left);
        }

        return ans;
    }
};