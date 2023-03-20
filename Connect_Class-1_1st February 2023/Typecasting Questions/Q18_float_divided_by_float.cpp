#include<iostream>
using namespace std;
int main(){
    int a = 2.3/2.1;  // Will only result in the integer part
    float b = 2.3/2.1; // Will be giving the output as the decimal (1.09524)
    char c = 110/2.1; // 52.38 which will be typecasted to 52 as the ASCII code of 4 hence 4 will be printed
    double d = 2.3/2.1; // Will be giving the output in decimal (1.09524)
    cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    return 0;
}