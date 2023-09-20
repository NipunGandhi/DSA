class Solution {
public:
    unordered_map<TreeNode*, int> umap;
    int rob(TreeNode* root) {
        if(root == NULL) return 0;
        if(umap.find(root) != umap.end()) return umap[root];
        
        int pick = root->val;
        if(root->left != NULL) pick += rob(root->left->left) + rob(root->left->right);
        if(root->right != NULL) pick += rob(root->right->left) + rob(root->right->right);
        
        int notPicked = rob(root->left) + rob(root->right);
        return umap[root] = max(pick, notPicked);
    }
};