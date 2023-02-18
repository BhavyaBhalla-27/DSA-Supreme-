#include<iostream>
#include<vector>
using namespace std;
int binarySearch(vector<int>arr,int target,int start,int end){
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
// pivot finding code
int pivotElement(vector<int>arr){
    int s = 0;
    int e = arr.size() - 1;
    int mid = s + (e-s)/2;
    while(s<e){
        if(mid + 1 < arr.size() && arr[mid]>arr[mid+1]){
            return mid;
        }
        if(mid - 1>=0 && arr[mid-1]>arr[mid]){
            return mid-1;
        }
        if(arr[s]>=arr[mid]){
            e = mid - 1;
        }
        else if(arr[s]<arr[mid]){
            s = mid;
        }
        mid = s + (e-s)/2;
    }
    return s;
}
int search(vector<int>arr,int target){
    int pivot = pivotElement(arr);
    if(target>=arr[0] && target<=arr[pivot]){
        // Search in left array
        int ans = binarySearch(arr,target,0,pivot); // search in left part of array
        return ans;
    }
    if(pivot + 1<arr.size() && target>=arr[pivot+1] && target<=arr[arr.size()-1]){
        int ans = binarySearch(arr,target,pivot+1,arr.size()-1); // search in right part of array
        return ans;
    }
    return -1; // if not found then return -1 which is not valid index
}
int main(){
    vector<int>arr{4,5,6,0,1,2,3};
    int target = 4;
    int index = search(arr,target);
    if(index == -1){
        cout<<"not found "<<endl;
    }
    else{
        cout<<"found "<<endl;
    }
    return 0;
}