// 3rd row of chart -> We can do modifications to verify all rows
#include<iostream>
using namespace std;
class Animal{
    // Parent Class / Base class
    public:
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
class Dog:private Animal{ // Child Class / Derived class
   
};
int main(){
    Dog d1;
    // d1.eat(); // Wont work
    // d1.age; // Wont work here 
    return 0;
}