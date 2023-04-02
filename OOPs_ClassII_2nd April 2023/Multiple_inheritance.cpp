#include<iostream>
using namespace std;
class A{
    public:
    int physics = 2;
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
    cout<<obj.physics<<endl;
    cout<<obj.chemistry<<endl;
    cout<<obj.maths<<endl;
    return 0;
}