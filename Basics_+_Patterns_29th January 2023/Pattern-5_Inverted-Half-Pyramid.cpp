// Pattern of inverted half pyramid
#include<iostream>
using namespace std;
int main(){
    int n = 6; // Generic code
    for(int row = 0;row<n;row=row+1){ // Outer for loop is for the number of rows
        for(int col = 0;col<n-row;col=col+1){ // Now number of stars to print is 1 more than the number of rows
            cout<<"*";
        }
        cout<<endl;
    }
}