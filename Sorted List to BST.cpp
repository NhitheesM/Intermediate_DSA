TreeNode<int>* treebuilder(TreeNode<int>* root,vector<int> arr, int low,int high){
    if(low>high) return NULL;
    int mid=(low+high)/2;
    root->data=arr[mid];
    root->left=new TreeNode<int>(0);
    root->right=new TreeNode<int>(0);
    root->left=treebuilder(root->left,arr,low,mid-1);
    root->right=treebuilder(root->right,arr,mid+1,high);
    return root;
}

TreeNode<int>* sortedListToBST(Node<int>* head)
{
	vector<int> arr;
    Node<int>* temp=head;
    while(temp){
        arr.push_back(temp->data);
        temp=temp->next;
    }
    int n = arr.size();
    TreeNode<int>* root=new TreeNode<int>(0);
    
    return treebuilder(root,arr,0,n-1);
}
