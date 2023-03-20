#include<iostream>
using namespace std;
void util(int *p){ // Copy of pointer is created
    p = p + 1; // Here we are changing pointer and not value present at address stored in p 
    *p = *p + 1; // Value present at a will get updated
}
int main(){
    int a = 5;
    int *p = &a;
    cout<<"Before "<<endl;
    cout<<a<<endl;
    cout<<p<<endl;
    cout<<*p<<endl;
    util(p);
    cout<<"After "<<endl;
    cout<<a<<endl;
    cout<<p<<endl;
    cout<<*p<<endl;
    return 0;
}