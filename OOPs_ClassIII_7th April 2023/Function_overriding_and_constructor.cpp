#include<iostream>
using namespace std;
class Animal{
    public:
        Animal(){
            cout<<"Animal constructor"<<endl;
        }
        void speak(){
            cout<<"Speaking"<<endl;
        }
};
class Dog : public Animal{
    public:
        Dog(){
            cout<<"Dog constructor"<<endl;
        }
        // Function overriding
        void speak(){
            cout<<"Barking"<<endl;
        }
};
int main(){
    Animal *a = new Animal(); // Animal constructor as after new Animal is written
    Dog *b = new Dog(); // Animal constructor then dog constructor as after new Dog is written
    Animal *c = new Dog(); // Animal constructor then dog constructor as after new Dog is written
    Dog *d = (Dog*) new Animal(); // Animal constructor as after new Animal is written
    return 0;
}