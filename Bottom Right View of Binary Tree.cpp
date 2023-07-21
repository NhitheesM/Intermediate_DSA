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
/*
    Time complexity: O(N)
    Space complexity: O(N)
    
    Where 'N' is number of nodes in binary tree.
*/

void bottomRightViewUtil(BinaryTreeNode<int>* root, int level, int& maxLevel, vector<int>& answer) {
    if (root == NULL) {
        return;
    }

    // Call the right child with same level
    bottomRightViewUtil(root->right, level, maxLevel, answer);

    // If current node at the maxlevel
    if (maxLevel <= level) {
        answer.push_back(root->data);
        maxLevel++;
    }
    // Call the left child with +1 level
    bottomRightViewUtil(root->left, level + 1, maxLevel, answer);
}

vector<int> bottomRightView(BinaryTreeNode<int>* root) {
    vector<int> answer;
    int maxLevel;

    // To store the answer node's value
    maxLevel = 0;  // Current maximum level
    bottomRightViewUtil(root, 0, maxLevel, answer);

    // To return sorted 'answer' list
    sort(answer.begin(), answer.end());
    return answer;
}