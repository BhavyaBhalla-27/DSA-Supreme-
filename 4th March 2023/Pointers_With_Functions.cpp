#include<iostream>
using namespace std;
void solve(int arr[]){ // Here pointer is passed and this is pass by reference concept
    cout<<"Size in solve function is - "<<sizeof(arr)<<endl; // Here 8 bytes will be printed as size of pointer will be printed
}
int main(){
    int arr[10] = {1,2,3,4};
    cout<<"Size of array in main function is - "<<sizeof(arr)<<endl; // 40 bytes will be the output here
    solve(arr);
    return 0;
}