#include<iostream>
using namespace std;
void merge(int arr[], int s, int e) {
    int mid = (s + e) / 2; // Calculate the middle index of the array
    int len1 = mid - s + 1; // Calculate the length of the left subarray
    int len2 = e - mid; // Calculate the length of the right subarray

    int *left = new int[len1]; // Dynamically create the left array of size len1
    int *right = new int[len2]; // Dynamically create the right array of size len2

    int k = s; // Initialize k with the starting index of the original array
    for (int i = 0; i < len1; i++) {
        left[i] = arr[k++]; // Copy elements from the original array to the left array
    }

    // Copy the values from the original array into the right array
    k = mid + 1; // Start from the index after the middle
    for (int i = 0; i < len2; i++) {
        right[i] = arr[k++]; // Copy elements from the original array to the right array
    }

    int leftIndex = 0; // Initialize an index for the left subarray
    int rightIndex = 0; // Initialize an index for the right subarray
    int mainArrayIndex = s; // Initialize an index for the main (original) array

    // Merge 2 sorted arrays
    while (leftIndex < len1 && rightIndex < len2) {
        if (left[leftIndex] < right[rightIndex]) {
            arr[mainArrayIndex++] = left[leftIndex++]; // Place smaller element in the main array
        } else {
            arr[mainArrayIndex++] = right[rightIndex++]; // Place smaller element in the main array
        }
    }

    // Copy any remaining elements from the left subarray into the main array
    while (leftIndex < len1) {
        arr[mainArrayIndex++] = left[leftIndex++];
    }

    // Copy any remaining elements from the right subarray into the main array
    while (rightIndex < len2) {
        arr[mainArrayIndex++] = right[rightIndex++];
    }
}

void mergeSort(int arr[],int s,int e){
    if(s >= e) // Single element remaining or invalid array
        return;
    int mid = s + (e-s)/2;
    // Left part sort
    mergeSort(arr,s,mid);
    // Right part sort
    mergeSort(arr,mid + 1,e);
    // Merge the sorted arrays
    merge(arr,s,e);
}
int main(){
    int arr[] = {38,27,43,3,9,20};
    int n = 6;
    int s = 0;
    int e = n - 1;
    mergeSort(arr,s,e);
    for(int i = 0; i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}
