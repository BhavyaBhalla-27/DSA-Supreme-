#include<iostream>
using namespace std;

int main() {
    int* p = nullptr; // Good practice to make it nullptr rather than to leave empty
    *p = 10;
    return 0;
}