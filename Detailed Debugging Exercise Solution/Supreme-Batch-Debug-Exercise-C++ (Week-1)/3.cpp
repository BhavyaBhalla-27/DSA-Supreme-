// Error - 1 Before using the variable, we have to first declare it (Added line-7)
// Error - 2 To multiply, we need to use * operator (Corrected line - 8)
// We can using cout instead of printf to print on screen
#include<iostream>
using namespace std;
int main() {
	float l, b;
    float P;
	P = 2*(l+b);
	cout<<"Perimeter = "<<P;
}