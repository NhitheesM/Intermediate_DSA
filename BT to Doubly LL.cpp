#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
void inorder(BinaryTreeNode<int>* root,vector<int> &arr){
    if(!root) return ;
    inorder(root->left,arr);
    arr.push_back(root->data);
    inorder(root->right,arr);

}
BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    vector<int> arr;
    inorder(root,arr);
    BinaryTreeNode<int>* head = new BinaryTreeNode<int>(arr[0]);
    head->left = NULL;
    head->right = NULL; // Set 'right' pointer of the last node to NULL

    BinaryTreeNode<int>* temp = head;
    int i = 1;

    while (i < arr.size()) {
        temp->right = new BinaryTreeNode<int>(arr[i]);
        BinaryTreeNode<int>* prev = temp;
        temp = temp->right;
        temp->left = prev;
        i++;
    }

    return head;

}
