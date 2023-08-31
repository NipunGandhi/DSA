class Solution {
public:
    void traverse(TreeNode* root, int& k, int& ans){
        if(root == NULL) return;
        traverse(root->left, k, ans);
        k--;
        if(k==0){
            ans = root->val;
            return;
        }
        traverse(root->right, k, ans);
    }

    int kthSmallest(TreeNode* root, int k) {
        int ans;
        traverse(root, k, ans);
        return ans;   
    }
};