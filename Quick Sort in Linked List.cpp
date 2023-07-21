#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/
int psort(vector<int>& arr,int low,int high){
    int p=arr[low];
    int i=low;
    int j=high;
    while(i<j){
        while(arr[i]<=p && i<=high){
            i++;
        }
        while(arr[j]>p && j>=low){
            j--;
        }
        if(i<j) swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);

    return j;
}

void quicksort(vector<int>& arr,int low,int high){
    if(low>=high) return;
    int pivot=psort(arr,low,high);
    quicksort(arr,low,pivot-1);
    quicksort(arr,pivot+1,high);
}

Node *quickSortLL(Node *head)
{
    vector<int> arr;
    Node* temp=head;
    while(temp){
        arr.push_back(temp->data);
        temp=temp->next;
    }
    quicksort(arr,0,arr.size()-1);
    int i=0;
    temp=head;
    while(i<arr.size()){
        temp->data=arr[i];
        i++;
        temp=temp->next;
    }
    return head;
}
