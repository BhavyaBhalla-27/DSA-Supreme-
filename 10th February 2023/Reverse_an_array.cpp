#include<iostream>
using namespace std;
int main(){
    int arr[5] = {1,2,3,4,5};
    int start = 0;
    int end = 4;
    // Swapping logic
    while(start<=end){
        // Swapping extreme ends
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
    // Normal printing of array
    for(int i = 0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}