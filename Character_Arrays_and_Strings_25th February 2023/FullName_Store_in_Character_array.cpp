#include<iostream>
using namespace std;
int main(){
    char ch[100];
    cout<<"Enter full name : ";
    cin>>ch; // ch does not read spaces, tabs or new line character.
    cout<<"Full name = "<<ch; // Only first name will be printed. 
    // getline function
    cin.getline(ch,100);
    cout<<ch;
}