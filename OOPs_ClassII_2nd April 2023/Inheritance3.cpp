// 2nd row of chart -> We can do modifications to verify all rows
#include<iostream>
using namespace std;
class Animal{
    // Parent Class / Base class
    protected:
        int age;
        void eat(){
            cout<<"Eating"<<endl;
        }
        void setAge(int age){
            this->age = age;
        }
        void getAge(){
            cout<<"Age = "<<age;
        }
};
class Dog:public Animal{ // Child Class / Derived class
    public:
    void print(){
        cout<<this->age; // Can be accessed inside the class
    }
};
int main(){
    Dog d1;
    // d1.eat(); // Will give error as base class was protected
    d1.print(); // Will work
    return 0;
}