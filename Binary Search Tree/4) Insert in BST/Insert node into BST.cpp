class Solution {
public:
    void traverse(TreeNode* root, int val){
        if(root->val > val){
            if(root->left == NULL){
                root->left = new TreeNode(val);
                return;
            } else {
                traverse(root->left, val);
            }
        } else {
            if(root->right == NULL){
                root->right = new TreeNode(val);
                return;
            } else {
                traverse(root->right, val);
            }
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL) {
            root = new TreeNode(val);
            return root;
        }
        TreeNode* temp = root;
        traverse(temp,val);
        return root;
    }
};