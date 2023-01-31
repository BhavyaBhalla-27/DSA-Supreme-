// Error - 1 We have use the semicolon to end the statement instead of : (Corrected on line 9)
// Error - 2 Comment are done using 2 // and not single / (Corrected on line 11)

#include<iostream>
using namespace std;
void main() {
	int i=0;
	i=i+1;
	cout<<i;
	/*print i \*/
    //i=i+1
	cout<<++i;
}