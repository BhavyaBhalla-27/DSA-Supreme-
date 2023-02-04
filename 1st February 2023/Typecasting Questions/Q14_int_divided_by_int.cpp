// Note that int/int is always an integer value
#include<iostream>
using namespace std;
int main(){
    int a = 3/2;  // Will give 1 as output as integer part 
    float b = 3/2; // Will give 1 as output
    char c = 96/2; // 48 which will be typecasted to char which is the ASCII code of 0
    double d = 3/2; // 1 as output again 
    cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    return 0;
}