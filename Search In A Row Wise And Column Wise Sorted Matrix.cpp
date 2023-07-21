#include <bits/stdc++.h> 
pair<int, int> search(vector<vector<int>> matrix, int x)
{
    int n=matrix.size();
    int i=0;
    while(i<n){
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(matrix[i][mid]==x){
                return {i,mid};
            }
            else if(matrix[i][mid]>x){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        i++;
    }
    return {-1,-1};

}
