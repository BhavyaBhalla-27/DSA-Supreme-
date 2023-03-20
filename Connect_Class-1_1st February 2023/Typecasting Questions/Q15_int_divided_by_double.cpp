// Note that int/float can be integer value if stored in the integer or it will be decimal number. (same output as that of float)
#include<iostream>
using namespace std;
int main(){
    int a = 3/(double)2.1;  // Will be typecasting to integer and hence give 1 as output
    float b = 3/(double)2.1; // Will give 1.42857 as output
    char c = 96/(double)1.9; // 50.5 which will be typecasted to the nearest ASCII code which is 50 which is the ASCII code of 2
    double d = 3/(double)2.1; // 1.42857 as output 
    cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    return 0;
}