class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return validate(root, LONG_MIN, LONG_MAX);
    }

    bool validate(TreeNode* root, long minRange, long maxRange){
        if(root == NULL) return true;
        if(root->val <= minRange || root->val >= maxRange){
            return false;
        }   
        return validate(root->left, minRange, root->val) && validate(root->right, root->val, maxRange); 
    }
};