class Solution {
public:
    TreeNode* buildSubTree(vector<int>& preorder, int preLow, int preHigh, vector<int>& inorder, int inLow, int inHigh, unordered_map<int, int>& umap){
        if(preLow > preHigh || inLow > inHigh) return NULL;
        TreeNode* root = new TreeNode(preorder[preLow]);
        int index = umap[root->val];
        root->left = buildSubTree(preorder, preLow + 1, preLow + index - inLow, inorder, inLow, index - 1, umap);
        root->right = buildSubTree(preorder, preLow + 1 +  index - inLow, preHigh, inorder, index + 1, inHigh, umap);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> umap;
        int size = preorder.size()-1;
        for(int i=0; i <= size; i++) umap[inorder[i]] = i;
        int preLow = 0, inLow = 0;
        int preHigh = size, inHigh = size;
        return buildSubTree(preorder, preLow, preHigh, inorder, inLow, inHigh, umap);
    }
};