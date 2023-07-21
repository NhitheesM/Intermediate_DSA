#include <bits/stdc++.h> 
void store(stack<int> &stack ,vector<int>& arr){
	if(stack.empty()) return;
	arr.push_back(stack.top());
	stack.pop();
	store(stack,arr);
}
void stacking(stack<int> &stack ,vector<int>& arr,int i){
	if(i>=arr.size()) return;
	stack.push(arr[i]);
	stacking(stack,arr,i+1);
}
void sortStack(stack<int> &stack)
{
	vector<int> arr;
	store(stack,arr);
	sort(arr.begin(),arr.end());
	stacking(stack,arr,0);
}