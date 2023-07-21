
bool isPalindrome(LinkedListNode<int> *head) {
    vector<int> arr;
    LinkedListNode<int>* temp=head;

    while(temp){
        arr.push_back(temp->data);
        temp=temp->next;
    }

    int n=arr.size();
    for(int i=0;i<n/2;i++){
        if(arr[i]!=arr[n-i-1]){
            return false;
        }
    }
    return true;
}
