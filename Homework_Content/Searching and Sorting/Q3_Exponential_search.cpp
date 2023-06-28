// Applying binary search on small part of array
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool binarySearch(vector<int>&arr,int start,int end,int target){
    while(start<=end){
        int mid = start + (end-start)/2;
        if(arr[mid] == target){
            return true;
        }
        else if(arr[mid] > target){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    return false;
}
bool expoSearch(vector<int>&arr,int target){
    // Handling 0th index case
    if(arr[0] == target)    
        return true;
    // Start from 1st index
    int i = 1;
    int n = arr.size();
    while(i<n && arr[i] <= target){
        // exponential search
        i = i * 2;
    }
    // find the starting index
    int start = i/2;
    // find the ending index
    int end = min(i,n-1);
    return binarySearch(arr,start,end,target);
}
int main(){
    vector<int>arr = {3,4,5,6,11,13,14,15,56,70};
    int target = 71;
    if(expoSearch(arr,target)){
        cout<<"Element found"<<endl;
    }
    else{
        cout<<"Not found";
    }
    return 0;
}