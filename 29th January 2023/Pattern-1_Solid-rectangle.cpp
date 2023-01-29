// This is the pattern of solid rectangle
#include<iostream>
using namespace std;
int main(){
    for(int row = 0;row<3;row=row+1){ // Outer for loop is for rows
        for(int col = 0;col<5;col=col+1){ // Inner for loop is for columns
            cout<<"* "; // Printing what needs to be printed
        }
        cout<<endl; // After printing for first row, we need to go to next row and hence endl is used
    }
}