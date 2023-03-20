#include<iostream>
using namespace std;
int main(){
    // Arithmetic operators
    int a = 5;
    int b = 3;
    cout<<a+b<<endl; // Addition
    cout<<a-b<<endl; // Subtraction
    cout<<a*b<<endl; // Multiplication
    cout<<a/b<<endl; // Division
    cout<<a%b<<endl; // Modulus 
    // Relational operators
    cout<<(a>b)<<endl;  // Greater than
    cout<<(a<b)<<endl;  // Lesser than
    cout<<(a==b)<<endl;  // Equal to
    cout<<(a!=b)<<endl;  // Not equal to
    cout<<(a<=b)<<endl;  // Less than or equal to
    cout<<(a>=b)<<endl;  // Greater than or equal to
    // Assignment operator
    int c = 3; // 3 is assigned to a
    // Logical operators
    cout<<(0&&0)<<endl; // Logical AND 
    cout<<(0||1)<<endl; // Logical OR
    cout<<(!1)<<endl;  //  Logical NOT
}