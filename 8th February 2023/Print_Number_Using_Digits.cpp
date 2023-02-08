#include<iostream>
using namespace std;
int main(){
    int digit[4] = {8,2,3,7}; // Digits are given in form of array
    int ans = 0; // Initially ans = 0
    for(int i = 0;i<4;i++){ 
        ans = ans * 10 + digit[i]; // formulae developed
    }
    cout<<ans<<endl;
    return 0;
}