#include<iostream>
using namespace std;
void rowWisePrint(int arr[][3],int rows,int cols){
    for(int i = 0;i<rows;i++){
        int sum = 0;
        for(int j = 0;j<cols;j++){
            sum = sum + arr[j][i];
        }
        cout<<"Printing sum of row "<<i<<" "<<sum<<endl;
    }
}
int main(){
    int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}}; 
    int rows = 3;
    int columns = 3;
    rowWisePrint(arr,rows,columns);
    return 0;
}
