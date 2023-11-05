void traverse(BinaryTreeNode<int> *node, int input, int& val){
	if(node==NULL||node->data == -1) return;
	if(node->data == input){
		val = node->data;
		return;
	}
	if(node->data < input){
		val = node->data;
		traverse(node->right,input,val);
	} else {
		traverse(node->left,input,val);
	}
}

int Floor(BinaryTreeNode<int> *node, int input)
{
	int val = -1;
	traverse(node,input,val);
	return val;
}
