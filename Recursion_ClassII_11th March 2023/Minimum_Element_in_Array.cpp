#include<iostream>
using namespace std;
void findMin(int arr[],int i,int size,int& mini){
    // Base Case
    if(i == size)
        return; 
    // Processing
    if(mini>arr[i]) // Finding the minimum element 
        mini = arr[i];
    // Recursive Relation
    findMin(arr,i+1,size,mini);
}
int main(){
    int arr[] = {1,2,3,4,5};
    int size = 5;
    int i = 0;
    int mini = INT_MAX;
    findMin(arr,i,size,mini);
    cout<<mini;
    return 0;
}