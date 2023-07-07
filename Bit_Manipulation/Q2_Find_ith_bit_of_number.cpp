#include<iostream>
using namespace std;
int main(){
    int n = 10;
    int i = 3;
    int mask = 1<<i;
    int ans = n&mask;
    if(ans == 0){
        cout<<0;
    }
    else{
        cout<<1;
    }
    return 0;
}