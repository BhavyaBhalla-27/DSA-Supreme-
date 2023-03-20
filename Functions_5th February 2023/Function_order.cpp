#include<iostream>
using namespace std;
int add(int a,int b); // function declaration
int main(){
    cout<<add(2,3); // function invoke
    return 0;
}
int add(int a,int b){ // function defintion
    return (a+b);
}