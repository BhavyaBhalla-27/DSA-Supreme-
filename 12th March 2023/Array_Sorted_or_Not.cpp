#include<iostream>
using namespace std;
bool checkSorted(int arr[],int i,int size){
    // Base Case
    if(i == size-1)
        return true; // As we have traversed full array
    // Processing (Solving 1 case only)
    if(arr[i] > arr[i+1])
        return false;
    // Recusive Relation
    return checkSorted(arr,i+1,size); // Move to the next element
}
int main(){
    int arr[] = {1,2,3};
    int size = 3;
    int i = 0;
    if(checkSorted(arr,i,size)){
        cout<<"Sorted array"<<endl;
    }
    else{
        cout<<"Not sorted"<<endl;
    }
}