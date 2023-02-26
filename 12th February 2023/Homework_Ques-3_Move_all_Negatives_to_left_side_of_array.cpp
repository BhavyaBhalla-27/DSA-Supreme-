#include<iostream>
#include<vector>
using namespace std;
void moveNegatives(vector<int>&arr){
    int i = 0;
    int j = arr.size() - 1;
    while(i<=j){
        if(arr[i] < 0){ // Element at correct position 
            i++; // Simply increment i 
        }
        else if(arr[j] < 0){ // Element not at correct position
            swap(arr[i],arr[j]); // Place negative at place of positive element 
            i++; // Simply increment i
            j--; // Decrement j
        }
        else{
            j--; // arr[j] > 0 , at right position and hence do j--
        }
    }
}
int main(){
    vector<int>arr{1,2,-4,-5,2,-7,3,2,-6,-8,-9,3,2,1};
    moveNegatives(arr);
    for(int i = 0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}