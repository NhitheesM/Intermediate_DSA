#include <bits/stdc++.h> 
BinaryTreeNode* mergeTrees(BinaryTreeNode* root1, BinaryTreeNode* root2)
{
    if(!root1 && !root2) return NULL;
    else if(!root1 and root2){
        return root2;
    }
    else if(!root2 and root1){
        return root1;
    }
    
    root1->data += root2 -> data ;
    root1->left = mergeTrees(root1->left,root2->left);
    root1->right = mergeTrees(root1->right,root2->right);

    return root1;
}
