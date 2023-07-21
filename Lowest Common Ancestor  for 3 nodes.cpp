//efficient

BinaryTreeNode<int>* lcaOfThreeNodes(BinaryTreeNode<int>* root, int node1, int node2, int node3) {
    if(root==NULL) return NULL;

	if(root->data==node1||root->data==node2||root->data==node3){
		return root;
	}
	BinaryTreeNode<int>* left=lcaOfThreeNodes(root->left,node1,node2,node3);
	BinaryTreeNode<int>* right=lcaOfThreeNodes(root->right,node1,node2,node3);

	if(left!=NULL && right!=NULL){
		return root;
	}
	else if (left!=NULL){
		return left;
	}
	else if (right!=NULL){
		return right;
	}

}



