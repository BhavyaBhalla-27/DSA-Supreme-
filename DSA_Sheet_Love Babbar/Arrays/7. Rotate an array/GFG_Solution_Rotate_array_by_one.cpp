// Given an array, rotate the array by one position in clock-wise direction.
// https://practice.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one2614/1
void rotate(int arr[], int n)
{
    int lastElement = arr[n-1];
    int i = n-2;
    for(;i>=0;i--){
        arr[i+1] = arr[i];
    }
    arr[0] = lastElement;
}