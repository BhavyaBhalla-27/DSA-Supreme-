#include<iostream>
using namespace std;
int main(){
    int num = 1;
    int n = 4;
    for(int i = 0;i<n;i++){ // 0 to n times 
        for(int j = 0;j<i+1;j++){ // formulae developed
            cout<<num<<" ";  // Printing counting only 
            num = num + 1;
        }
        cout<<endl; // as row is completed go to new line
    }
    return 0;
}