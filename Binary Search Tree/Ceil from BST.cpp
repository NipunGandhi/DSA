#include <bits/stdc++.h> 
void traverse(BinaryTreeNode<int> *node, int x, int& val){
    if(node == NULL || node->data == -1) return;
    if(node->data >= x){
        val = node->data;
        traverse(node->left,x,val);
    } else {
        traverse(node->right,x,val);
    }
}

int findCeil(BinaryTreeNode<int> *node, int x){
    int val = -1;
    traverse(node,x,val);
    return val;
}