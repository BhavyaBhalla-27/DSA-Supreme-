#include<iostream>
using namespace std;
int main(){
    int arr[3][3]; // 2D array with 3 rows and 3 columns (Matrix -> Total of 9 elements can be stored)
    // Initialization
    int brr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    // Output in 2D array
    cout<<brr[2][2]<<endl; // Output will be 9
    cout<<brr[1][1]<<endl; // Output will be 5
    cout<<brr[0][2]<<endl; // Output will be 3
    // Row-wise access
    for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
            cout<<brr[i][j]<<" ";
        }
        cout<<endl;
    }
    // Column-wise access
    for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
            cout<<brr[j][i]<<" ";
        }
        cout<<endl;
    }
    // input
    int crr[3][3];
    // row - wise input
    for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
            cin>>crr[i][j];
        }
    }
    // print row wise
    for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
            cout<<crr[i][j]<<" ";
        }
        cout<<endl;
    }
    // column wise input
    for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
            cin>>crr[j][i];
        }
    }
    // print row wise
    for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
            cout<<crr[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}