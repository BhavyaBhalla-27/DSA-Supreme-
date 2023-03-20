#include<iostream>
#include<vector>
using namespace std;
void printArr(vector<int>arr){
    for(int i = 0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}
void selectionSort(vector<int>&arr){
    int n = arr.size();
    for(int i = 0;i<n-1;i++){ // n elements , n-1 rounds will be there
        int minIndex = i; // the element which we are standing is assumed to be minimum
        for(int j = i+1;j<n;j++){
            if(arr[minIndex] > arr[j]){
                minIndex = j; // updating minimum
            }
        }
        swap(arr[minIndex],arr[i]); // swapping and placing minimum element at right index
    }
}
int main(){
    vector<int>arr{10,1,4,8,5,7};
    cout<<"Printing before sorted "<<endl;
    printArr(arr);
    cout<<"Printing array after sorting "<<endl;
    selectionSort(arr);
    printArr(arr);
    return 0;
}