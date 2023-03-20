#include<iostream>
using namespace std;
int main(){
    int n = 5; // general case
    for(int i = 0 ; i<n;i++){ // number of rows
        // print spaces
        int space = n - i - 1;
        for(;space>=0;space--){
            cout<<" ";
        }
        // print numbers
        int start = i+1; // Starting number is row number + 1 (observation)
        for(int j = 0;j<i+1;j++){ // Numbers that will be printed are equal to row number + 1 (observation)
            cout<<start; // Print start
            start = start + 1;
        }
        // reverse counting
        start = 2*i; // First number of pattern-2 is even so we start from 2*i
        for(int j = 0;j<i;j++){
            cout<<start; 
            start--; // reverse counting
        }
        cout<<endl;
    }

    return 0;
}