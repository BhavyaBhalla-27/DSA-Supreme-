#include<iostream>
using namespace std;
void moveNegative(int arr[], int n){
    int i=0, j=n-1;
    while(i<j){
        while(arr[i]<0){ // swap when a positive element is encountered
            i++;
        }
        while(arr[j]>0){ // swap when a negative element is encountered
            j--;
        }
        // Additional condition to check whether i<j. This condition we have also discussed in the code of quick sort while doing the partition.
        if(i<j)
            swap(arr[i], arr[j]); // swap the elements
    }
}
int main(){
    int n = 5;
    int arr[n] = {2, -3, -1, 5, -4};
    moveNegative(arr, n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}