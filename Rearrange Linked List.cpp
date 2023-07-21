#include <bits/stdc++.h> 
/************************************************************

    Following is the linked list node structure

    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* rearrangeList(Node<int>* head)
{
    vector<int> store;
    Node<int>* temp=head;
    while(temp){
        store.push_back(temp->data);
        temp=temp->next;
    }
    int n=store.size();
    Node<int>* root=new Node<int>(0);
    temp=root;
    
    for(int i=0 ;i<n/2;i++){
        temp->next=new Node<int>(store[i]);
        temp->next->next=new Node<int>(store[n-i-1]);
        temp=temp->next->next;
    }
    if(n%2==1){
        temp->next=new Node<int>(store[n/2]);
    }
    return root->next;
}