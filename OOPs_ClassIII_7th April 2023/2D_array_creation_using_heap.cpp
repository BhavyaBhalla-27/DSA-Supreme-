#include<iostream>
using namespace std;
int main(){
    int row = 5;
    int col = 3;
    // Creation step
    int **arr = new int*[5];
    for(int i = 0;i<row;i++){
        arr[i] = new int[col];
    }
    // Put values in 2D array
    for(int i = 0;i<row;i++){
        for(int j = 0;j<col;j++){
            arr[i][j] = 0;
        }
    }
    // Printing the 2D array
    for(int i = 0;i<row;i++){
        for(int j = 0;j<col;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    // De-allocation
    for(int i = 0;i<col;i++){
        delete []arr[i];
    }
    delete []arr;
    return 0;
}