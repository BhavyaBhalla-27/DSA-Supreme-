#include<iostream>
using namespace std;
int printEven(int n){
    int sum = 0;
    for(int i = 1;i<=n;i++){
        sum = sum + i;
    }
    return sum;
}
int main(){
    int n = 10;
    cout<<printEven(n);
}