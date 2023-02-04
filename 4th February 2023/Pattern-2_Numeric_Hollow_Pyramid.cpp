#include<iostream>
using namespace std;
int main(){
    int n = 7;
    for(int i = 0;i<n;i++){
        // Space print kro
        int space = n - i - 1; // formuale developed for spaces
        for(;space>=0;space--){
            cout<<" "; // printing the spaces
        }
        // Printing the characters (spaces and numbers both)
        int start = 1;// Numbering always start from 1 in the pattern
        for(int j = 0;j<2*i+1;j++){ //developed a formulae till when the loop will run
            if(i==0 || i==n-1){ // Behaviour is different for 1st and the last row that's why if condition
                if(j%2==0){ // Now number is only printed when the column number is an even number
                    cout<<start<<" "; // Number is printed
                    start = start + 1;
                }
            }
            else{
                if(j==0){ // For first column we always have to print 1. 
                    cout<<1;
                }
                else if(j==2*i){
                    cout<<i+1; // For last column we always have to print the number which is one more than the row number
                }
                else{
                    cout<<" "; // And in between we have to print the spaces
                }
            }
        }
        cout<<endl;
    }
    return 0;
}