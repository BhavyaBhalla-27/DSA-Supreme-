#include<iostream>
using namespace std;
bool findKey(int arr[][3],int rows,int cols,int key){
    for(int i = 0;i<rows;i++){
        for(int j = 0;j<cols;j++){
            // Comparing the key to be searched with the element
            if(arr[i][j] == key){
                return true;
            }
        }
    }
    return false;
}
int main(){
    int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}}; 
    int rows = 3;
    int columns = 3;
    int key = 10;
    if(findKey(arr,rows,columns,key)){
        cout<<"Found Element ";
    }
    else{
        cout<<"Absent ";
    }
    
    return 0;
}