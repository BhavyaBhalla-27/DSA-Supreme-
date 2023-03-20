// Pattern of numeric half pyramid
#include<iostream>
using namespace std;
int main(){
    int n = 5; // Generic code
    for(int row = 0;row<n;row=row+1){ // Outer for loop is for the number of rows
        for(int col = 0;col<row+1;col=col+1){ 
            cout<<col+1<<" "; // Just change what we have to print
        }
        cout<<endl;
    }
}