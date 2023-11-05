class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return compareMethod(root->left,root->right);
    }
	
    bool compareMethod(TreeNode* left,TreeNode* right){
        if(left == NULL || right == NULL) return left == right; 
        if(left->val != right->val) return false;
        return compareMethod(left->left,right->right) && compareMethod(left->right,right->left); 
    }
};