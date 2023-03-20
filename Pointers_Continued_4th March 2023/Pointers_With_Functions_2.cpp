#include<iostream>
using namespace std;
void update(int *p,int *q){
    *p = 100; // Updated value present at index 1 
    *q = 200; // Updated pointer present at index 2
}
int main(){
    int arr[4] = {10,20,30,40};
    int *p = &arr[1]; // Pointer to 1st index
    int *q = &arr[2]; // Pointer to 2nd index 
    update(p,q); // Passed by reference 
    for(int i = 0;i<4;i++){
        cout<<arr[i]<<" "; // Array will be printed
    }
    return 0;
}