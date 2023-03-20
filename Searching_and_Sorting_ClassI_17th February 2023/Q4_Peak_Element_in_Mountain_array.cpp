#include<iostream>
using namespace std;
int peakElement(int arr[],int size){
    int s = 0;
    int e = size - 1;
    int mid = s + (e-s)/2;
    while(s<e){
        if(arr[mid]<arr[mid+1]){
            s = mid + 1; // search in right part as mid can not be peak and lies in the ascending line
        }
        else{
            e = mid; // e = mid; as if we are at peak element, then e = mid - 1, we will loose peak element
        }
        mid = s + (e-s)/2;
    }
    return s; // return e; will also work
}
int main(){
    int arr[] = {0,10,5,2};
    int size = 4;
    int ans = peakElement(arr,size);
    cout<<ans<<endl;
    return 0;
}