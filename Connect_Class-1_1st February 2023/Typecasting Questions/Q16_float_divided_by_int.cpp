#include<iostream>
using namespace std;
int main(){
    int a = 2.3/2;  // Will only result in the integer part
    float b = 2.3/2; // Will be giving the output as the decimal (1.15)
    char c = 96.7/2; // 48.35 which will be typecasted to 48 as the ASCII code of 0 hence 0 will be printed
    double d = 2.3/2; // Will be giving the output in decimal (1.15)
    cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    return 0;
}