class BSTIterator {
public:
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        countLeft(root);
    }

    void countLeft(TreeNode* node){
        while(node){
            st.push(node);
            node = node->left;
        }
    }
    
    int next() {
        TreeNode* element = st.top();
        st.pop();
        int val = element->val;
        if(element->right) countLeft(element->right);
        return val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};
