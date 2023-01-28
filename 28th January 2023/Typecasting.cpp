#include<iostream>
using namespace std;
int main(){
    char ch = 97; // Implicit type conversion from integer to character
    cout<<ch<<endl;
    int num = 'b'; // Implicit type conversion from character to integer
    cout<<num<<endl;
    double d = 5.2;
    int x = (int)d + 2; // Explicit type conversion from double to integer
    cout<<x;
}