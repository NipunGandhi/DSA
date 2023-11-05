class Solution {
public:
    int traverse(TreeNode* root, int highestVal){
        int left = 0, right = 0;

        if(root->left != NULL){
            if(root->left->val >= highestVal){
                left = 1 + traverse(root->left, root->left->val);
            } else {
                left = traverse(root->left, highestVal);
            }
        }

        if(root->right != NULL){
            if(root->right->val >= highestVal){
                right = 1 + traverse(root->right, root->right->val);
            } else {
                right = traverse(root->right, highestVal);
            }
        }

        return right + left;
    }

    int goodNodes(TreeNode* root) {
        if(root == NULL) return 0;
        return 1 + traverse(root, root->val);        
    }
};