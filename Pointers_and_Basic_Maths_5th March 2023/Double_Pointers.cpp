#include<iostream>
using namespace std;
int main(){
    int a = 5; // Simply creating the variable
    int *p = &a; // Pointer to variable
    int **q = &p; // Pointer to pointer = double pointer

    cout<<&a<<endl; // Address of a block
    cout<<a<<endl; // 5
    cout<<p<<endl; // Address of a block
    cout<<*p<<endl; // 5
    cout<<&p<<endl; // Address of pointer p block
    cout<<q<<endl; // Address of pointer p block
    cout<<*q<<endl; // Address of a block
    cout<<**q<<endl; // 5
    cout<<&q<<endl; // Address of q block
    return 0;
}