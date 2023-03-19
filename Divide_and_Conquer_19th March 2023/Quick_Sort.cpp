#include<iostream>
using namespace std;
// Partition function
int partition(int arr[],int s,int e){
    // Step - 1 => Select the pivot element
    int pivotIndex = s;
    int pivot = arr[s];
    // Step - 2 => Find right place of pivot element
    int count = 0;
    for(int i = s + 1;i<=e; i++){ // Full array is from s to e. We started from s + 1 because pivot was on s
        if(arr[i] <= pivot)
            count++;
    }
    // Now we have known the correct place of pivot element. So place it there
    int rightIndex = s + count; // Adding s as always s wont be zero.
    swap(arr[pivotIndex],arr[rightIndex]);
    pivotIndex = rightIndex; // Update the index of pivot
    // Step - 3 => Create the partition now such that left elements of pivot is lesser than pivot and right elements should be greater than pivot
    int i = s;
    int j = e;
    while(i<pivotIndex && j>pivotIndex){
        // No Need to swap
        // i++ condition satisify or not
        while(arr[i] <= pivot)  
            i++;
        // j-- condition satisfy or not
        while(arr[j] > pivot)
            j--;
        // Need to swap now 
        // verify once that i is behind pivotIndex and j > pivotIndex => Elements found to swap
        if(i<pivotIndex && j>pivotIndex){
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    return pivotIndex;
}
void quickSort(int arr[],int s,int e){
    // Base case
    if(s >= e) // s == e is single element which is already sorted and s > e is invalid array
        return;
    // Partition Logic
    int p = partition(arr,s,e);
    // Recursion Logic
    // Call for left array
    quickSort(arr,s,p-1);
    // Call for right array
    quickSort(arr,p+1,e);
}
int main(){
    int arr[] = {8,1,3,4,20,50,30};
    int n = 7;
    int s = 0;
    int e = n - 1;
    quickSort(arr,s,e);
    for(int i = 0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}