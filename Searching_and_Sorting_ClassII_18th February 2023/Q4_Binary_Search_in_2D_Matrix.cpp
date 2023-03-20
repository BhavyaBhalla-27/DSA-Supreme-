#include<iostream>
using namespace std;
bool binarySearch(int arr[][4],int rows,int cols,int target){
    int s = 0;
    int e = rows*cols - 1;
    int mid = s + (e-s)/2;
    while(s<=e){
        int rowIndex = mid/cols; // formulae
        int colIndex = mid % cols; // formulae
        if(arr[rowIndex][colIndex]==target)
            return true;
        if(arr[rowIndex][colIndex]<target){
            s = mid + 1; // right part
        }
        else{
            e = mid - 1; // left part
        }
        mid = s + (e-s)/2; // update mid
    }
    return false;
}
int main(){
    int arr[5][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16},{17,18,19,20}};
    int rows = 5;
    int cols = 4;
    int target = 29;
    bool ans = binarySearch(arr,rows,cols,target);
    if(ans){
        cout<<"Found"<<endl;
    }
    else{
        cout<<"Not found ";
    }
    return 0;
}