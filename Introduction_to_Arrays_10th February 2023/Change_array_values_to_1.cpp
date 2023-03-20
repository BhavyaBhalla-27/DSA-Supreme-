#include<iostream>
using namespace std;
int main(){

    int arr[5] = {1,2,3,4,5};
    for(int i = 0;i<5;i++){
        // Changing value to 1 
        arr[i] = 1;
    }
    for(int i = 0;i<5;i++){
        // Just print the array. We get changed values
        cout<<arr[i]<<" ";
    }
    return 0;
}