// Pivot element is the element at which the monotonic order breaks
#include<iostream>
#include<vector>
using namespace std;
int pivotElement(vector<int>arr){
    int s = 0;
    int e = arr.size() - 1;
    int mid = s + (e-s)/2;
    while(s<e){
        if(mid + 1 < arr.size() && arr[mid]>arr[mid+1]){ // mid + 1 < arr.size() so that valid index
            return mid;
        }
        if(mid - 1>=0 && arr[mid-1]>arr[mid]){ // mid - 1 >=0 so that valid index
            return mid-1;
        }
        if(arr[s]>=arr[mid]){
            e = mid - 1; // search in left array
        }
        else if(arr[s]<arr[mid]){
            s = mid; // search in right array
        }
        mid = s + (e-s)/2;
    }
    return s;
}
int main(){
    vector<int>arr{3,4,5,6,7,1,2};
    int pivot = pivotElement(arr);
    cout<<"Pivot = "<<arr[pivot]<<endl;
    return 0;
}