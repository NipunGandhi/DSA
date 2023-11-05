class Solution {
public:
    int kthSmallest(TreeNode* root, int& k) {
        if(root == NULL) return -1; 
        int val = kthSmallest(root->left, k);
        if(val != -1) return val;
        k--;
        if(k==0) return root->val;
        return kthSmallest(root->right, k);
    }  
};