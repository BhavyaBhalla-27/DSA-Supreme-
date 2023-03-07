#include<iostream>
using namespace std;
int power(int a,int b){
    int ans = 1;
    for(int i = 1;i<=b;i++){
        ans = ans * a; // Simply multiply a, b times with itself 
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