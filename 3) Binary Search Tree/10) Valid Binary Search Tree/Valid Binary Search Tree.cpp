class Solution {
public:
    bool range(TreeNode* node, long min, long max){
        if(node == NULL) return true;
        if(node->val > min && node->val < max){
            return range(node->left, min, node->val) && range(node->right, node->val, max);
        }
        return false;
    }
    
    bool isValidBST(TreeNode* root) {
        return range(root, LONG_MIN, LONG_MAX);
    }
};