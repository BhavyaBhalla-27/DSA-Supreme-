#include<iostream>
using namespace std;
int main() {
    // int* p = NULL;  --> Use dyanamic memory allocation
    int *p = new int;
    *p = 42;
    delete p; // Deleting the memory taken
    return 0;
}