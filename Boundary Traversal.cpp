#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
/*
    Time Complexity: O(N)
    Space Complexity: O(N)

    Where N is the number of nodes in the Binary Tree.
*/

// Functions to traverse on each part.

void leftTraversal(TreeNode<int>* root,vector<int> &ans){
    if( !root || (!root->left && !root->right)) return ;

    ans.push_back(root->data);
    if(root->left){
        leftTraversal(root->left,ans);
    }
    else{
        leftTraversal(root->right,ans);
    }
}

void rightTraversal(TreeNode<int>* root,vector<int> &ans){
    if( !root || (!root->left && !root->right)) return ;

    if(root->right){
        rightTraversal(root->right,ans);
    }
    else{
        rightTraversal(root->left,ans);
    }
    ans.push_back(root->data);
}

void midTraversal(TreeNode<int>* root,vector<int> &ans){
    if(!root) return ;
    if( !root->left and !root->right ){
        ans.push_back(root->data);
    }
    midTraversal(root->left,ans);
    midTraversal(root->right,ans);
}

vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int>ans;
    if(!root) return ans;

    ans.push_back(root->data);
    leftTraversal(root->left,ans);
    midTraversal(root->left,ans);
    midTraversal(root->right,ans);
    rightTraversal(root->right,ans);

    return ans;
}