class Solution {
public:
    unordered_map<TreeNode*, bool> umap;
    bool isSubtreeHelper(TreeNode* root, TreeNode* subRoot){
      if(root == NULL || subRoot == NULL) return root == subRoot;
      if(umap.find(root) != umap.end()) return umap[root];
      if(root->val != subRoot->val) return umap[root] = false;
      return isSubtreeHelper(root->left, subRoot->left) && isSubtreeHelper(root->right, subRoot->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL) return false;
        return umap[root] = isSubtreeHelper(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};