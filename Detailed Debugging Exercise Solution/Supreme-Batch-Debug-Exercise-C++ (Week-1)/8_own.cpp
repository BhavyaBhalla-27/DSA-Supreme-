#include<iostream>
using namespace std;
int main(){
    int n = 5;
    for(int i = 0;i<n;i++){
        // First print the spaces
        int space = n-i-1;
        for(;space>=0;space--){
            cout<<" ";
        }
        // Printing the first layer of stars
        for(int j = 0;j<2*i + 1;j++){
                // i == n-1 for last row printing
                // j == 0 for first column printing
                // j == 2*i for last column printing
                if(i==n-1 || j==0 || j==2*i){
                    cout << "*";
                    }
                else { 
                    cout<<" ";
                }
        }
        cout<<endl;
    }
    return 0;
}