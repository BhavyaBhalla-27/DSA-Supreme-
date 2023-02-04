#include<iostream>
using namespace std;
int main(){
    int n = 4; // general pattern
    // Upper half 
    for(int i = 0;i<n;i++){ // for number of rows
        for(int j = 0;j<i+1;j++){
                cout<<i+1; // for ith row we are printing i + 1 number
                if(j!=i){
                    cout<<"*"; // For last character don't print star 
                }
        }
        cout<<endl;
    }
    // Lower half
    for(int i = 0;i<n;i++){ // for rows
        for(int j = 0;j<n-i;j++){ 
            cout<<n-i; // for ith row n-i is the number that is getting printed
            if(j!=n-i-1){ // last column condition
                cout<<"*";
            }
        }
        cout<<endl;
    }

    return 0;
}