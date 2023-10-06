class Solution {
public:
    void traverse(TreeNode* root, int& val){
        if(root == NULL) return;
        traverse(root->right, val);
        root->val += val;
        val = root->val;
        traverse(root->left, val);
    }

    TreeNode* convertBST(TreeNode* root) {
        int val = 0;
        traverse(root, val);
        return root;
    }
};