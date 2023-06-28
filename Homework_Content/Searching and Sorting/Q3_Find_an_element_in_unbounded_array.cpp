#include<iostream>
using namespace std;
bool binarySearch(int arr[],int start,int end,int target){
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
bool search(int arr[],int target){
    // Method - 1 (Brute force)
    // int i = 0;
    // while(true){
    //     if(arr[i] > target){
    //         return false;
    //     }
    //     if(arr[i] == target){
    //         return true;
    //     }
    //     i++;
    // }
    // return false;

    // Method - 2 (Exponential search)
    int i = 0;
    int j = 1;
    while(arr[j] < target){
        i = j;
        j = j * 2;
    }
    int start = i;
    int end = j;
    return binarySearch(arr,start,end,target);
}
int main(){
    int arr[] = {3,4,5,15,67,78,90,110,115,116,120,136};
    int target = 116;
    if(search(arr,target)){
        cout<<"Element found";
    }
    else   
        cout<<"Element not found";
    return 0;
}