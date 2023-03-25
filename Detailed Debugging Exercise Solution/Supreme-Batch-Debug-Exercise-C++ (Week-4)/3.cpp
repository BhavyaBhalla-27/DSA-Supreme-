// Selection sort is based on the idea that to put the minimum element for that particular pass to its right place.
// The logic for calculating the index of minimum element was right but then placing it at the right place was wrong.
// So simply put swap(arr[i],arr[minIndex]) instead of swap(arr[j],arr[minIndex]) as i was taken to be the initial element and that need to be swapped with the minimum element.

#include<iostream>
using namespace std;
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1;j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[i],arr[minIndex]);
    }
}
int main(){
    int arr[] = {5,2,4,1,3};
    int n = 5;
    selectionSort(arr,n);
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}