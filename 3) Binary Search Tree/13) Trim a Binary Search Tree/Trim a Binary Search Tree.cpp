class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root == NULL) return NULL;
        
        if(root->val > low && root->val > high) {
            return trimBST(root->left, low, high);
        } else if (root->val < low && root->val < high){
            return trimBST(root->right, low, high);
        }

        root->left = trimBST(root->left, low, root->val);
        root->right = trimBST(root->right, root->val, high);
        return root;
    }
};