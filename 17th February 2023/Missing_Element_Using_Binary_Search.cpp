#include<iostream>
#include<vector>
using namespace std;
int findElement(vector<int>arr){
    int s = 0;
    int e = arr.size() - 1;
    int mid = s + (e-s)/2;
    while((e-s)>1){
        if(arr[s] - s != arr[mid] - mid){
            e = mid; // search in left 
        }
        else if(arr[e] - e != arr[mid] - mid){
            s = mid; // search in right
        } 
        mid = s + (e-s)/2; // update mid
    }
    return arr[s] + 1; // return arr[s] + 1
}
int main(){
    vector<int>arr{1,2,3,4,5,7,8,9,10};
    int missingElement = findElement(arr);
    cout<<"Missing Element = "<<missingElement<<endl;
    return 0;
}