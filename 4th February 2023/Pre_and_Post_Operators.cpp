#include<iostream>
using namespace std;
int main(){
    int a = 10;
    // Pre increment means -> first increment and then use
    // Post increment means -> first use and then increment
    cout<<(++a)<<endl; // op is 11
    cout<<(a++)<<endl; // op is 11
    cout<<a<<endl; // op is 12
    int c = 6;
    int d = ++c + 1; // -> 8 as the output
    int e = 5;
    cout<<(++e) * (++e)<<endl; // Homework question (find out why)
    return 0;
}