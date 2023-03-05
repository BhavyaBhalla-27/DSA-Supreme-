#include<iostream>
using namespace std;
int main(){
    int a = 5;
    int &b = a; // Reference variable creation
    cout<<a<<endl; // 5 will be printed
    cout<<b<<endl; // 5 will be printed
    b++;
    cout<<a<<endl; // 6 will be printed
    cout<<b<<endl; // 6 will be printed
    return 0;
}