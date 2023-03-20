#include<iostream>
#include<limits.h>
using namespace std;
int maximum(int arr[][3],int rows,int cols){
    int maxi = INT_MIN;
    for(int i = 0;i<rows;i++){
        for(int j = 0;j<cols;j++){
            if(arr[i][j]>maxi){
                maxi = arr[i][j];
            }
        }
    }
    return maxi;
}
int minimum(int arr[][3],int rows,int cols){
    int mini = INT_MAX;
    for(int i = 0;i<rows;i++){
        for(int j = 0;j<cols;j++){
            if(arr[i][j]<mini){
                mini = arr[i][j];
            }
        }
    }
    return mini;
}
int main(){
    int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}}; 
    int rows = 3;
    int columns = 3;
    cout<<"Maxi = "<<maximum(arr,rows,columns)<<" and  Mini = "<<minimum(arr,rows,columns)<<endl;
    
    return 0;
}