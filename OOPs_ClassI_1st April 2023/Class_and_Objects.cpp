#include<iostream>
using namespace std;
// Creation of class
class Animal{
    // State or properties
    // Access modifier
    private:
    int weight;
    public:
    int age;
    string name;
    // Behaviour or functions
    void eat(){
        cout<<"I am eating";
    }
    void sleep(){
        cout<<"I am sleeping";
    }
    // Setter 
    // void setWeight(int w){
    //     weight = w;
    // }
    // this keyword
    void setWeight(int weight){
        this->weight = weight; // Differentiate 
    }
    // Getter
    void getWeight(){
        cout<<weight;
    }
    
};
int main(){
    // Object creation
    Animal ramesh;
    // Accessing property of object
    ramesh.age = 12;
    ramesh.name = "lion";
    cout<<ramesh.age<<" "<<ramesh.name<<endl;
    // Calling member functions
    ramesh.eat();
    cout<<endl;
    // Getter and setter use
    ramesh.setWeight(101);
    ramesh.getWeight();

    // Dyanamic Memory allocation
    Animal *suresh = new Animal;
    // 1st way (dot operator)
    (*suresh).age = 15;
    (*suresh).name = "billi";
    // 2nd way (Arrow operator)
    suresh->name = "sher";
    suresh->age = 16;
    suresh->eat();
    return 0;
}