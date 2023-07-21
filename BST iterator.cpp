#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

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

class BSTiterator
{   public:
    int index;
    vector<int> store;

    BSTiterator(TreeNode<int> *root)
    {   
        index=0;
        inorder(root);
    }

    int next()
    {
        int next=store[index];
        index++;
        return next;
    }

    bool hasNext()
    {
        if(index<store.size()) return true;
        return false;
    }

    void inorder(TreeNode<int>* node){
        if(node==NULL) return ;
        
        inorder(node->left);
        store.push_back(node->data);
        inorder(node->right);
    }
};


/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/