#include<iostream>
using namespace std;
int main(){
    int n = 6; // For general pattern, we take n
    for(int i = 0;i<n;i++){ // This for loop is for number of rows
        // First print the spaces
        int space = n - i - 1;
        for(;space>=0;space--){
            cout<<" ";
        }
        // Then print the stars
        for(int j = 0;j<i+1;j++){
            cout<<"* ";
        }
        cout<<endl;
    }

    return 0;
}