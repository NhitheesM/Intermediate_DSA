#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure.

    template <typename T>
    class TreeNode {
        public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
void preorder(TreeNode<int>* node,vector<int> &store){
    if(!node) return;
    store.push_back(node->data);
    preorder(node->left,store);
    preorder(node->right,store);
}
TreeNode<int>* flattenBinaryTree(TreeNode<int>* root) {
    if (root == nullptr)
        return nullptr;

    vector<int> store;
    preorder(root,store);
    TreeNode<int>* llroot=new TreeNode<int>(0);
    TreeNode<int>* temp=llroot;
    for(int i=0;i<store.size();i++){
        temp->right=new TreeNode<int>(store[i]);
        temp=temp->right;
    }
    return llroot->right;
}
