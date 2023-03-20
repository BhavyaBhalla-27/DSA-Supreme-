#include<iostream>
#include<vector>
using namespace std;
int binarySearch(vector<int>arr,int target){
    int s = 0;
    int e = arr.size() - 1;
    int mid = s + (e-s)/2;
    while(s<=e){
        // Checking three condition of nearly sorted array
        if(arr[mid] == target){
            return mid;
        }
        if(mid - 1 >= s && arr[mid-1] == target){ // check for valid index mid - 1>=0 -> modifying condition to mid - 1 >=s
            return mid - 1;
        }
        if(mid + 1 <= e && arr[mid + 1] == target){ // check for valid index mid + 1 < arr.size() -> modifying condition to mid + 1 <= e
            return mid + 1;
        }
        // right part search
        if(target>arr[mid]){
            s = mid + 2;
        }
        // left part search
        else{
            e = mid - 2;
        }
        // update mid
        mid = s + (e-s)/2;
    }
    return -1;
}

int main(){
    vector<int>arr{10,3,40,20,50,80};
    int target = 700;
    int ans = binarySearch(arr,target);
    if(ans==-1){
        cout<<"Not Found "<<endl;
    }
    else{
        cout<<"Found "<<endl;
    }
    return 0;
}