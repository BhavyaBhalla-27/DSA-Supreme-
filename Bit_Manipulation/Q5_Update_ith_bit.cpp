#include<iostream>
using namespace std;
int main(){
    int n = 10;
    int i = 1;
    int target = 1;
    // Step - 1 Clear the ith bit
    int mask = ~(1<<i);
    n = n & mask;
    // Step - 2 Create mask
    int mask1 = target<<i;
    // Step - 3 Bitwise OR operation
    n = n | mask1;
    cout<<n;
    return 0;
}