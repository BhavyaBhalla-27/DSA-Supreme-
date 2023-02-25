#include<iostream>
#include<vector>
using namespace std;
int binarySearch(vector<int>arr,int key){
    int s = 0;
    int e = arr.size() - 1;
    int mid = s + (e-s)/2;
    while(s<=e){
        // First case -> found element at mid index
        if(arr[mid] == key){
            return mid;
        }
        else if(arr[mid] > key){
            // search in right
            s = mid + 1;
        }
        else{
            // search in left
            e = mid - 1;
        }
        // update mid 
        mid = s + (e-s)/2;
    }
    return -1; // if element not found 
}
int main(){
    vector<int>arr{13,10,9,6,2,1};
    int key = 11;
    int index = binarySearch(arr,key);
    if(index == -1){
        cout<<"Element not found ";
    }
    else{
        cout<<"Element found ";
    }
    return 0;
}