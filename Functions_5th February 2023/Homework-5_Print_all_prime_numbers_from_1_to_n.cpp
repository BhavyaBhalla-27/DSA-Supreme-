#include<iostream>
using namespace std;
bool checkPrime(int num){
    int factor = 0;
    if(num<2){
        return false;
    }
    for(int i = 2;i<num;i++){
        if(num%i==0){
            factor++;
            break;
        }
    }
    if(factor==1){
        return false;
    }
    else{
        return true;
    }
}
void printPrime(int n){
    for(int i = 2;i<=n;i++){
        if(checkPrime(i)){
            cout<<i<<endl;
        }
    }
}
int main(){
    int n = 100;
    printPrime(n);
    return 0;
}