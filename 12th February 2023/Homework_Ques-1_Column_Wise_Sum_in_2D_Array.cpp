#include<iostream>
using namespace std;
void columnWisePrint(int arr[][3],int rows,int cols){
    // Simply do column wise traversal
    for(int i = 0;i<rows;i++){
        int sum = 0; // Initially sum = 0 for each new column
        for(int j = 0;j<cols;j++){ // Traversing till number of columns
            sum = sum + arr[j][i]; // Column wise traversal
        }
        cout<<"Sum of "<<(i+1)<<" column is "<<sum<<endl;
    }
}
int main(){
    int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int rows = 3;
    int cols = 3;
    columnWisePrint(arr,rows,cols);
    return 0;
}