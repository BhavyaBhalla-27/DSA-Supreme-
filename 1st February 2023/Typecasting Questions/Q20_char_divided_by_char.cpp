#include<iostream>
using namespace std;
int main(){
    int a = 'A' / 'B'; // ASCII code of A is 65 and ASCII code of B is 66 so 65/66 is 0.984 and hence only integer part will be considered as it will be typecasted to int. Hence 0 is the output. 
    char b = 'A'/'A';  // ASCII value = 1 is occupied by smiley symbol and hence that will be the output
    float c = 'A'/'B';  // Works as int/int
    double d = 'A'/'B'; // Works as int/int
    cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    return 0;
}