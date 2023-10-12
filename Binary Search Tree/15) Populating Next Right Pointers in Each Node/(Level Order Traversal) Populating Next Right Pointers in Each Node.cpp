class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return root;
        queue<pair<Node*, int>> q;
        q.push({root, 0});

        while(!q.empty()){
            Node* element = q.front().first;
            int level = q.front().second;
            q.pop();
            if(q.empty() || q.front().second != level) element->next = NULL;
            else element->next = q.front().first;

            if(element->left) q.push({element->left, level+1});
            if(element->right) q.push({element->right, level+1});
        }
        return root;
    }
};