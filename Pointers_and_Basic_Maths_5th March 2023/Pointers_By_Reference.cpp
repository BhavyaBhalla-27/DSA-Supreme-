#include<iostream>
using namespace std;
void solve(int*& p){
    p = p + 1; // Address will be modified as pointer is passed by reference
}
int main(){
    int a = 5;
    int *p = &a;
    cout<<"Before"<<p<<endl; // Address of p
    solve(p);
    cout<<"After"<<p<<endl; // p will have modified address 
    return 0;
}