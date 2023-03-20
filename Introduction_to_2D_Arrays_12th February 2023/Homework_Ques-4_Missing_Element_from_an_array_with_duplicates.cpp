#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
void printMissingElement(vector<int>&arr){
    for(int i = 0;i<arr.size();i++){
        int index = abs(arr[i]);
        if(arr[index - 1] > 0){
            // mark it visited
            arr[index - 1] = -arr[index - 1] ;
        }
    }
    // Traverse the array and print index + 1 for all the positive elements
    cout<<"Missing elements are "<<endl;
    for(int i = 0;i<arr.size();i++){
        if(arr[i] > 0){
            cout<<(i+1)<<" ";
        }
    }
}
int main(){
    vector<int>arr{1,3,3,3,4};
    printMissingElement(arr);
    return 0;
}