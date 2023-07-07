#include<iostream>
using namespace std;
int main(){
    int n = 8;
    int count = 0;
    // Method - 1
    // while(n!=0){
    //     if((n&1) == 1){
    //         count++;
    //     }
    //     n = n>>1;
    // }

    // Method - 2
    while(n!=0){
        // Remove last set bit
        n = (n&(n-1));
        count++;
    }
    cout<<count;
    return 0;
}