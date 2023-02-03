#include<iostream>
using namespace std;
int main(){
    double num = 9;  // It should have stored as 9.0 but the compiler will ignore .0 decimal and hence the output will 9.
    cout<<num<<endl;
    return 0;
}