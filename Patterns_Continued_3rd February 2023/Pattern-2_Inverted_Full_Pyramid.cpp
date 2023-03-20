#include<iostream>
using namespace std;
int main(){
    int n = 6; // For general pattern, we take n
    for(int i = 0;i<n;i++){ // This for loop is for number of rows
        // First print the spaces
        int space = i;
        for(;space>=0;space--){
            cout<<" ";
        }
        // Then prin    t the stars
        for(int j = 0;j<n-i;j++){
            cout<<"* ";
        }
        cout<<endl;
    }

    return 0;
}