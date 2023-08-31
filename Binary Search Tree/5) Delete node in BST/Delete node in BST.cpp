class Solution {
public:
    TreeNode* findMin(TreeNode* root){
        while(root->left != NULL){
            root = root->left;
        }
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;

        if(key > root->val){
            root->right = deleteNode(root->right,key);
        } else if (key < root->val){
            root->left = deleteNode(root->left,key);
        } else {
            if(root->right == NULL){
                return root->left;
            } else if(root->left == NULL){
                return root->right;
            } else {
                TreeNode* minVal = findMin(root->right);
                root->val = minVal->val;
                root->right = deleteNode(root->right, root->val);
                return root;
            }
        }
        
        return root;
    }
};