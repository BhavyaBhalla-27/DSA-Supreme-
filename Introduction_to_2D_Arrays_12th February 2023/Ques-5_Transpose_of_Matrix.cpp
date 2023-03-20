#include<iostream>
using namespace std;
void transpose(int arr[][3],int rows,int cols){
    for(int i = 0;i<rows;i++){
        for(int j = 0;j<i;j++){
            swap(arr[i][j],arr[j][i]);
        }
    }
}
int main(){
    int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}}; 
    int rows = 3;
    int columns = 3;
    cout<<"Printing array first "<<endl;
    for(int i = 0;i<rows;i++){
        for(int j = 0;j<columns;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Taking transpose "<<endl;
    transpose(arr,rows,columns);
    cout<<"Printing transposed array "<<endl;
    for(int i = 0;i<rows;i++){
        for(int j = 0;j<columns;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
