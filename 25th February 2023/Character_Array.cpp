#include<iostream>
using namespace std;
int main(){
    // First way of taking input
    char ch[100];
    cout<<"Enter your name ";
    cin>>ch; // entire sequence is taken as input
    cout<<"Your name is "<<ch<<endl;
    // Second way of taking input
    char ch1[5];
    cin>>ch1[0];
    cout<<"Character entered = "<<ch1[0];
    return 0;
}