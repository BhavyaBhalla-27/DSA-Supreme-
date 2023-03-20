// This is the pattern of hollow shape (generic code for both square and rectangle). If we want hollow square the simple put r and c as equal values
    
#include<iostream>
using namespace std;
int main(){
    int r = 4; // For generic code
    int c = 6; // For generic code
    for(int row = 0;row<r;row=row+1){ // Outer for loop is for rows
        for(int col = 0;col<c;col=col+1){ // Inner for loop is for columns
            // Only first row and last row will have all the stars 
            if(row == 0 || row == r-1){
                cout<<"* ";
            }
            // What if the row is not first and not last 
            else{
                // For the remaining rows only first and the last column will have the start
                if(col==0 || col== c-1){
                    cout<<"* ";
                }
                // Except first and last columns there will be spaces instead of *
                else{
                    cout<<"  ";
                }
            }
        }
        cout<<endl; // After printing for first row, we need to go to next row and hence endl is used
    }
}