#include <bits/stdc++.h> 
/*************************************************************
    
    Following is the Binary Tree node structure:

    class TreeNode{

        public :
            int data;
            TreeNode *left;
            TreeNode *right;

            TreeNode(int data) {
                this -> data = data;
                left = NULL;
                right = NULL;
            }

            ~TreeNode() {
            if (left){
            delete left;
            }

            if (right){
            delete right;
            }
        }   
    };

*************************************************************/
void inorder(TreeNode<int>* root,vector<int> &arr){
    if(!root) return ;
    inorder(root->left,arr);
    arr.push_back(root->data);
    inorder(root->right,arr);
}

vector<int> mergeSortedArrays(vector<int> &arr1, vector<int> &arr2) {
    int i = 0, j = 0;
    vector<int> arr;
    
    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j]) {
            arr.push_back(arr1[i]);
            i++;
        } else {
            arr.push_back(arr2[j]);
            j++;
        }
    }
    
    while (i < arr1.size()) {
        arr.push_back(arr1[i]);
        i++;
    }
    
    while (j < arr2.size()) {
        arr.push_back(arr2[j]);
        j++;
    }
    
    return arr;
}

TreeNode<int>* treebuilder(vector<int> arr, int low,int high){
    if(low>high) return NULL;
    int mid=(low+high)/2;
    TreeNode<int>* root=new TreeNode<int>(arr[mid]);
    root->left=treebuilder(arr,low,mid-1);
    root->right=treebuilder(arr,mid+1,high);
    return root;
}

TreeNode<int> * mergeBST(TreeNode<int> *root1, TreeNode<int> *root2) {
    vector<int> arr1,arr2;
    inorder(root1,arr1);
    inorder(root2,arr2);
    vector<int> final = mergeSortedArrays(arr1, arr2);
    int n = final.size();
    
    return treebuilder(final,0,n-1);  
}
