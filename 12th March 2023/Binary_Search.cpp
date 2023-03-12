#include<iostream>
#include<vector>
using namespace std;
int searchElement(vector<int>&arr,int start,int end,int target){
    // Base Case
    if(start > end)
        return -1; // Element not found 
    // 1 case solve kro
    int mid = start + (end - start)/2; // Find mid
    if(arr[mid] == target){ // If element found at mid index, then return the index of array
        return mid;
    }
    // Recursive Relation
    else if(arr[mid] > target){
        // Search in left
        return searchElement(arr,start,mid-1,target);
    }
    else{   
        // Search in right
        return searchElement(arr,mid+1,end,target);
    }
}
int main(){
    vector<int>arr{1,2,3,4,5,6,7,8,9,10};
    int n = arr.size();
    int start = 0;
    int end = n - 1;
    int target = 11;
    int ans = searchElement(arr,start,end,target);
    if(ans == -1){
        cout<<"Not Found";
    }
    else{
        cout<<"Found";
    }
    return 0;
}