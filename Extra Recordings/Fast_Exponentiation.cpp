#include<iostream>
using namespace std;
int power(int a,int b){
    int ans = 1;
    while(b > 0){
        if(b & 1){ // Checking odd by bitwise method as it is faster than modulo
            ans = ans * a;
        }
        a = a*a;
        b = b>>1;
    }
    return ans;
}
int main(){
    int a = 2;
    int b = 10;
    int ans = power(a,b);
    cout<<ans;
    return 0;
}