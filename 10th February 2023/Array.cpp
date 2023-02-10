#include<iostream>
using namespace std;
int main(){
    int arr[7]; // declaration of integer array of 28 bytes space
    int a[53]; // integer array of 53 size
    char ch[106]; // character array of 106 size
    bool arr1[10]; // boolean array of 10 size
    int arr2[] = {1,2,3,4,5}; // initialization of array
    // Printing array values
    int array[5] = {1,2,3,4,5};
    for(int i = 0;i<5;i++){ // i is the index
        cout<<array[i]<<" ";
    }
    // Taking the input and initializing the array
    int array1[10];
    cout<<"Enter array values "<<endl;
    for(int i = 0;i<10;i++){
        cin>>array1[i];
    }
    
    return 0;   
}