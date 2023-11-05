class Solution {
    public:
    int maxPathSum(TreeNode* root) {
        int max_sum = INT_MIN;
        maxPathSumRecursive(root, max_sum);
        return max_sum;
    }

    int maxPathSumRecursive(TreeNode* root, int& max_sum) {
        if(root == NULL) return 0;

        int left = maxPathSumRecursive(root->left, max_sum);
        int right = maxPathSumRecursive(root->right, max_sum);
        
        int ans = max(root->val, root->val + max({left, right}));
        max_sum = max({max_sum, root->val + right + left, ans});

        return ans;
    }
};