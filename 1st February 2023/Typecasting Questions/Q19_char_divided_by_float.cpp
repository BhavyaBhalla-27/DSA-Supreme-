#include<iostream>
using namespace std;
int main(){
    int a = 'A' / 2.1; // A is type casted to 65 and then 65/2.1 gives 30.95 which will be typecasted to intger and hence gives 30 as the output
    char b = 'e'/2.1; // ASCII code of e is 101 and 101/2.1 is 48.09 which will be typecasted to lowest ASCII value which is 48 and hence 0 is the output
    float c = 'A'/2.1; // 65/2.1 gives the output as 30.9524
    double d = 'A'/2.1; // 65/2.1 gives the output as 30.9524
    cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    return 0;
}