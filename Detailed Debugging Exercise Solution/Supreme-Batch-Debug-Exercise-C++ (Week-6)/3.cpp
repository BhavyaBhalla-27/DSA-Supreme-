#include<iostream>
using namespace std;
int* foo() {
    int *p = new int; // Dyanamic memory allocation. However previous code was also working.
    *p = 10; // Value present is changed to 10. Actualy value is updated as pointer is pointing to the actual value
    return p;
}

int main() {
    int* q = foo();
    cout << *q << endl; // Expected output: 10, Actual output: some random value
    return 0;
}