class Solution {
public:
    int height(TreeNode* root){
        if(root == NULL) return 0;
        int left = 1 + height(root->left);
        int right = 1 + height(root->right);
        return max(left,right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        int total = height(root->right) + height(root->left); 
        int leftDiameter = diameterOfBinaryTree(root->left);
        int rightDiameter = diameterOfBinaryTree(root->right);
        return max({total, leftDiameter, rightDiameter});
    }
};