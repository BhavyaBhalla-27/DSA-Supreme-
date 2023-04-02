#include<iostream>
using namespace std;
class A{
    public:
    int chemistry = 7;
};
class B{
    public:
    int chemistry = 3;
};
class C : public A,public B{
    public:
    int maths = 4;
};
int main(){
    C obj;
    cout<<obj.A::chemistry<<endl; // Scope resolution fix
    cout<<obj.B::chemistry<<endl; // Scope resolution fix
    cout<<obj.maths<<endl;
    return 0;
}