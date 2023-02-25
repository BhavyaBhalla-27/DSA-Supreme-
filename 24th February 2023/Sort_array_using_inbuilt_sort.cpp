#include<iostream>
#include<algorithm> // algorithm header file to be included if we want to use sort inbuilt function
using namespace std;
void printArr(int arr[],int n){
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int arr[] = {5,4,3,2,1};
    int n = 5;
    sort(arr,arr+n); // arr -> beginning address and arr+n -> ending address
    printArr(arr,n);
    return 0;
}