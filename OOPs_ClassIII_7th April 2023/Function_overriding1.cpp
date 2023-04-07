#include<iostream>
using namespace std;
class Animal{
    public:
        virtual void speak(){ // Virtual keyword used in base class
            cout<<"Speaking"<<endl;
        }
};
class Dog : public Animal{
    public:
        // Function overriding
        void speak(){
            cout<<"Barking"<<endl;
        }
};
int main(){
    Animal *a = new Animal();
    a->speak(); // speaking is printed
    Dog *b = new Dog();
    b->speak(); // barking is printed
    // Upcasting
    Animal *c = new Dog();
    c->speak(); // speaking is printed if virtual keywork not used, else barking is printed
    // Downcasting
    Dog *d = (Dog*) new Animal();
    d->speak(); // barking is printed if virtual keywork not used, else speaking is printed
    return 0;
}