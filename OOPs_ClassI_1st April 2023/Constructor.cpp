#include<iostream>
using namespace std;
class Animal{
    int age;
    public:
    // default constructor
    Animal(){
        cout<<"Default constructor called"<<endl;
    }
    // parameterized constructor
    Animal(int age){
        this->age = age;
        cout<<"Parameterized constructor called"<<endl;
    }
    // Copy constructor
    Animal(Animal& obj){
        this->age = age;
        cout<<"Copy constructor called";
    }
};
int main(){
    Animal suresh; // Default constructor
    Animal ramesh(30); // Parameterized constructor
    Animal copy(suresh); // Copy constructor
    return 0;
}