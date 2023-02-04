#include<iostream>
using namespace std;
int main(){
    int n = 3; // General pattern
    // Upper part
    for(int i = 0;i<n;i++){ // For number of rows
        // First half pyramid pattern
        for(int j = 0;j<n-i;j++){
            cout<<"*";
        }
        // Now print the spaces between pattern-1 and pattern-2
        for(int j = 0;j<2*i+1;j++){
            cout<<" ";
        }
        // Now again print the half pyramid pattern
        for(int j = 0;j<n-i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
    // Lower part
    for(int i = 0;i<n;i++){
        // First print pyramid
        for(int j = 0;j<i+1;j++){
            cout<<"*";
        }
        // Spaces between pattern-1 and pattern-2
        for(int j = 0; j<2*n - 2*i - 1;j++){
            cout<<" ";
        }
        // Again print pyramid
        for(int j = 0;j<i+1;j++){
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}