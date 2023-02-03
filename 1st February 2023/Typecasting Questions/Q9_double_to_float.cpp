// Float - 7 digits of precision
// Double - 15 digits of precision
#include<iostream>
using namespace std;
int main(){
    float num = 9.66666666666666; // Such high precision number can not be stored in double and hence it will be rounded off to the precision value of float.
    cout<<num<<endl;
    return 0;
}