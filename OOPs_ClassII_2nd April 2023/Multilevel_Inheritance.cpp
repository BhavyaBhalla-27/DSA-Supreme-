#include<iostream>
using namespace std;
class Fruit{
    public:
    string name = "Mango";
};
class Mango : public Fruit{
    public:
    int weight;
};
class Alphanso : public Mango{
    public:
    int sugarLevel;
};
int main(){
    Alphanso a;
    cout<<a.name<<" "; // Will work due to multilevel inheritance
    

    return 0;
}