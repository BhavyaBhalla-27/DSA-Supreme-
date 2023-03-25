// Instead of n-2, write n-1
// Also added some optimization that if in a particular pass, there is no swap then this means array is already sorted and hence exit.

#include<iostream>
using namespace std;
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if(!swapped){
            break;
        }
    }
}
int main(){
    int arr[] = {5,2,4,1,3};
    int n = 5;
    bubbleSort(arr,n);
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}