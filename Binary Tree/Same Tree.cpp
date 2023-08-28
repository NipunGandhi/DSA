class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL || q == NULL) return p == q;
        if(p->val != q->val) return false;

        bool compareLeft = isSameTree(p->left,q->left);
        bool compareRight = isSameTree(p->right,q->right);

        return compareLeft && compareRight;
    }
};