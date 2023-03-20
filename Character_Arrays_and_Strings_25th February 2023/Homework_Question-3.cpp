#include<iostream>
#include<string.h>
using namespace std;
int main(){
    // Use different varients of replace
    string str = "This is a short phrase";
    str.replace(22,1,3,'!'); // 1st varient
    cout<<str<<endl;
    str = "This is a short phrase";
    str.replace(8,6,"a shorty",7); //2nd varient
    cout<<str<<endl;
    str = "This is a short phrase";
    str.replace(8,6,"a shorty"); // 3rd varient -> In 2nd varient, just don't use the last value to make 2nd varient 
    cout<<str<<endl;
    str = "This is a short phrase";
    str.replace(19,6,"a shorty",7,6); // 4th varient
    cout<<str<<endl;
    return 0;
}