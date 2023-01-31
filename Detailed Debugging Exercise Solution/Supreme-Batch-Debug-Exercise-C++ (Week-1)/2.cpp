// Error - 1 We have to use insertion operator (<<) with cout. (Corrected Line 7)
// Error - 2 We have to print sum of numbers and the numbers are positive and hence result will also be positive so we have to remove - from -(i+j) (Corrected in Line 7)
#include<iostream>
using namespace std;
int main() {
	short i=2300, j=4322;
	cout<<"i+j="<<-(i+j);
}