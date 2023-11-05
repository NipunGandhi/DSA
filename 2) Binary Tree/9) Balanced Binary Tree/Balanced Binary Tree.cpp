class Solution {
public:
    int height(TreeNode* root, bool &ans){
        if(root == NULL) return 0;
        int left = height(root->left,ans) + 1;
        int right = height(root->right,ans) + 1;
        if(ans) ans = abs(right-left) <= 1;
        return max(left,right);
    }

    bool isBalanced(TreeNode* root){
        if(root == NULL) return true;
        int left = 0, right = 0; bool ans = true;
        if(root->left != NULL) left = height(root->left,ans);
        if(root->right != NULL) right = height(root->right,ans);
        if(ans) ans = abs(right-left) <= 1;
        return ans;
    }
};