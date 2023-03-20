// Homework - 9 Solid half diamond 
#include<iostream>
using namespace std;
int main(){
    int n = 6;
    // Pattern - 1
    for(int i = 0;i<n;i++){
        for(int j = 0;j<i+1;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
    // Pattern - 2
    for(int i = 0;i<n-1;i++){
        for(int j = 0;j<n-i-1;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
    return 0;
}