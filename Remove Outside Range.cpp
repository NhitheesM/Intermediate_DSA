BinaryTreeNode<int>* removeOutsideRange(BinaryTreeNode<int> *root, int min, int max)
{
    if(root==NULL) return NULL;

    root->left = removeOutsideRange(root->left,min,max);
    root->right= removeOutsideRange(root->right,min,max);

    if(root->data < min){
        return root->right;
    }
    if(root->data > max){
        return root->left;
    }

    return root;
}
