#include<iostream>
using namespace std;
int main(){
    int a = 'A' / 2; // A is type casted to 65 and then 65/2 gives 32.5 which will be typecasted to intger and hence gives 32 as the output
    char b = 'a'/2; // ASCII code of a is 97 and 97/2 is 48 as int/int is always integer and hence 48 is the ASCII code of 0 and hence 0 will be printed.
    float c = 'A'/2; // A is typecasted to 65 which is an integer and hence int/int will be integer always and hence  32 will be the output
    double d = 'A'/2; // A is typecasted to 65 which is an integer and hence int/int will be integer always and hence  32 will be the output
    cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    return 0;
}