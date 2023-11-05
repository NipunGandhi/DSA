class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        if(root == p) return p;
        else if(root == q) return q;

        TreeNode* node1 = lowestCommonAncestor(root->left,p,q);
        TreeNode* node2 = lowestCommonAncestor(root->right,p,q);
        
        if(node1 && node2) return root;
        else if(node1) return node1;
        else if(node2) return node2;
        return NULL;
    }
};