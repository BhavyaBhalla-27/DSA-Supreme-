#include<iostream>
using namespace std;
void solve(int *p){
    *p = *p + 10; // value at address stored in p is incremented by 10
}
int main(){
    int a = 5;
    int *ptr = &a; // Pointer to integer variable a 
    solve(ptr); // Pointer is passed to the function
    cout<<a; // modified value will be printed i.e. 15
    return 0;
}