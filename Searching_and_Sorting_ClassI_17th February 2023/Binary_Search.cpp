#include<iostream>
using namespace std;
int binarySearch(int arr[],int size,int target){
    int start = 0;
    int end = size-1;
    int mid = (start+end)/2;
    while(start<=end){ // exit when start>end and this indicates that we didn't find the target value
        if(arr[mid]==target){ // if mid element is target, then return mid index
            return mid;
        }
        else if(target<arr[mid]){
            end = mid-1; // Search in left part
        }
        else{
            start = mid + 1; // Search in right part 
        }
        mid = start + (end-start)/2; // Update mid value with updated start and end values
    }
    return -1; // element not found then return -1 which is not a valid index
}
int main(){
    int arr[] = {1,3,7,9,11,13,15,19};
    int index = binarySearch(arr,8,15);
    if(index==-1){
        cout<<"Element not found "<<endl;
    }
    else{
        cout<<"Found at index = "<<index<<endl;
    }
    return 0;
}