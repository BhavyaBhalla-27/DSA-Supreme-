#include<iostream>
using namespace std;
class Car{
    string name;
    int id;
    string color;
    public:
        // Friend function will be used only to overload the << and >> operators.
        friend istream& operator >> (istream& input,Car& c1);
        friend ostream& operator << (ostream& output,Car& c1);
};
istream& operator >> (istream& input,Car& c1){
    cout<<"Enter the value of name of car"<<endl;
    input>>c1.name;
    cout<<"Enter the id of the car"<<endl;
    input>>c1.id;
    cout<<"Enter the color of the car"<<endl;
    input>>c1.color;
    return input;
}
ostream& operator << (ostream& output,Car& c1){
    cout<<"Name of car is "<<endl;
    output<<c1.name<<endl;
    cout<<"Id of car is "<<endl;
    output<<c1.id<<endl;
    cout<<"Color of car is "<<endl;
    output<<c1.color<<endl;
    return output;
}
int main(){
    Car c1;
    cin>>c1;
    cout<<c1<<endl;
    return 0;
}