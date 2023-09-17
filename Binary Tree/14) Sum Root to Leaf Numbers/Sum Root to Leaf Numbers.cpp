class Solution {
public:
    int ans(TreeNode* root, int val){
        if(root == NULL) return 0;
        val = val * 10 + root->val;
        if(root->left == NULL && root->right == NULL) return val;
        int left = ans(root->left, val);
        int right = ans(root->right, val);
        return left + right;
    }

    int sumNumbers(TreeNode* root) {
        return ans(root, 0);
    }
};