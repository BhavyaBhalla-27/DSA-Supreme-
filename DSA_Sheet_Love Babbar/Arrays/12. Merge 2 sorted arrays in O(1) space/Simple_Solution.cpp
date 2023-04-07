#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void mergeSortedArrays(vector<int>&arr1,vector<int>&arr2){
    int i = arr1.size() - 1; // Start from last index of arr1
    int j = 0; // Start from 0th index of arr2
    // Traverse until any one or both the arrays finishes
    while(i>=0 && j<arr2.size()){
        if(arr1[i] > arr2[j]){
            swap(arr1[i--],arr2[j++]);
        }   
        else{
            break; // We are given sorted arrays so condition in if wont be satisfied again
        }
    }
    // Sort both the arrays
    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());

    // Additional step -> Printing the array
    for(auto k:arr1){
        cout<<k<<" ";
    }
    for(auto k:arr2){
        cout<<k<<" ";
    }
}
int main(){
    vector<int>arr1{1,3,5,7};
    vector<int>arr2{0,2,6,8,9};
    mergeSortedArrays(arr1,arr2);
    return 0;
}