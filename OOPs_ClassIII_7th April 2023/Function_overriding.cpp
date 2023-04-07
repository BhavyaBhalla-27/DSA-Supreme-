#include<iostream>
using namespace std;
class Animal{
    public:
        void speak(){
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
    Animal a;
    a.speak(); // Speaking will come
    Dog d;
    d.speak(); // If explicitly we didnt define the speak function in dog, then speaking would be the output
    // but here we have written speak function and hence barking will be printed
    return 0;
}