#include<iostream>
using namespace std;
void printArrayElements(int arr[],int size){
    // Base Case
    if(size == 0)
        return;
    // Processing
    cout<<arr[0]<<" ";
    // Recursive Relation
    printArrayElements(arr+1,size-1);
}
int main(){
    int arr[] = {1,2,3,4,5};
    int size = 5;
    int i = 0;
    printArrayElements(arr,size);
    return 0;
}