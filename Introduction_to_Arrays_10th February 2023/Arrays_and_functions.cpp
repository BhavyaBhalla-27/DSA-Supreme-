#include<iostream>
using namespace std;
// Here original array is passed by default
void incr(int arr[],int size){ // good practice to pass size along with the array
    arr[0] = arr[0] + 10;
}
int main(){
    int arr[5] = {1,2,3,4,5};
    cout<<arr[0]<<endl; // 1 is printed
    incr(arr,5); 
    cout<<arr[0]; // Actual array is updated (1+10 = 11 is printed)
    return 0;
}