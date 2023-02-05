#include<iostream>
using namespace std;
// Method - 1 but % is a heavy operation
int printEven(int n){
    int sum = 0;
    for(int i = 1;i<=n;i++){
        if(i%2==0)
        sum = sum + i;
    }
    return sum;
}
// Method - 2
int printEven1(int n){
    int sum = 0;
    for(int i = 2;i<=n;i=i+2){ // Even number starts from 2 and adding 2 to even number will give even number
        sum = sum + i;
    }
    return sum;
}
int main(){
    int n = 10;
    cout<<printEven(n)<<endl;
    cout<<printEven1(n);
}