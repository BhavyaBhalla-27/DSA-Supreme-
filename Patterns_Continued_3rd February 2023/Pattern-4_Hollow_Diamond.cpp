#include<iostream>
using namespace std;
int main(){
    int n = 6; // General pattern 
    // First we have to print the hollow full pyramid
    for(int i = 0;i<n;i++){ // Number of rows
        // first print spaces
        int space = n - i - 1;
        for(;space>=0;space--){
            cout<<" ";
        }
        // Print stars
        for(int j = 0;j<2*i+1;j++){
            // First or last character
            if(j==0 || j==2*i){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
    // Print inverted full pyramid pattern
    for(int i = 0;i<n;i++){
        // Space print
        int space = i;
        for(;space>=0;space--){
            cout<<" ";
        }
        // Print stars
        for(int j = 0;j<2*n - 2*i - 1;j++){
            // First or last column
            if(j==0 || j == 2*n - 2*i - 2){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}