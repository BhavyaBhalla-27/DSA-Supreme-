#include<iostream>
using namespace std;
void findMaximum(int arr[],int i,int size,int& maxi){
    // Base Case
    if(i == size)
        return; 
    // Processing
    if(maxi<arr[i]) // Maximum element condition
        maxi = arr[i];
    // Recursive Relation
    findMaximum(arr,i+1,size,maxi);
}
int main(){
    int arr[] = {1,2,3,4,5};
    int size = 5;
    int i = 0;
    int maxi = INT_MIN;
    findMaximum(arr,i,size,maxi);
    cout<<maxi;
    return 0;
}