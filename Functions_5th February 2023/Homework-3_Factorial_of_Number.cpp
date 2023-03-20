#include<iostream>
using namespace std;
int factorial(int num){
    int fact = 1;
    for(int i = 1;i<=num;i++){
        fact = fact * i;
    }
    return fact;
}
int main(){
    cout<<factorial(11);
    return 0;   
}