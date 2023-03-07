#include<iostream>
using namespace std;
long long int powMod(long long int x,long long int n,long long int m){
    long long int ans = 1;
    // apply fast exponentiation 
    while(n > 0){
        if(n & 1){ // odd case
            ans = (ans * x)%m; // May be Bigger value and hence do mod to bring in range 
        }
        x = (x * x)%m; // May be Bigger value and hence do mod to bring in range 
        n = n >> 1; 
    }
    return ans%m;
}
int main(){
    long long int x = 3;
    long long int n = 2;
    long long int m = 4;
    long long int ans = powMod(x,n,m);
    cout<<ans;
    return 0;
}