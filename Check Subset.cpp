#include <bits/stdc++.h> 
bool checkSubset(vector < int > & arr1, vector < int > & arr2, int n, int m) {
    unordered_map<int,int> countMap;
    for(int i=0;i<n;i++){
        countMap[arr1[i]]++;
    }
    for(int j=0;j<m;j++){
        if(countMap[arr2[j]]>0){
            countMap[arr2[j]]--;
        }
        else{
            return false;
        }
    }
    return true;

}