// Homework - 4 Hollow full pyramid
#include<iostream>
using namespace std;
int main(){
    int n = 6;
    for(int i = 0; i < n;i++){
        // Print the spaces first
        int space = n - i - 1; // formulae for spaces
        for(;space>=0;space--){
            cout<<" ";
        }
        // Print the stars now
        for(int j = 0;j<2*i + 1;j++){
            if(j == 2*i || j == 0 || (i == n-1 && j%2==0)) // j == 2*i is last column
                                                           // j == 0 is first column
                                                           // i == n-1 && j%2 == 0 (last row and even column)
                cout<<"*";
            else{
                cout<<" ";
            }
                
        }
        cout<<endl;
    }
    return 0;
}