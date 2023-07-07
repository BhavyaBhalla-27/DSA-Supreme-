#include<iostream>
using namespace std;
int main(){
    int n = 10;
    int i = 2;
    int j = 0;
    // Create a
    int a = (-1<<(i+1));
    // Create b
    int b = (1<<j) - 1;
    // Create mask
    int mask = a | b;
    // Do bitwise and with input
    n = n & mask;
    cout<<n;
    return 0;
}