#include<iostream>
#include<map>
using namespace std;
int main(){
    map<int,char>myMap; // Creating a map syntax 
    // Inserting values into myMap
    myMap[0] = 'a';
    cout<<myMap[0]<<endl; // a will be printed
    cout<<myMap[1]; // Empty 
    return 0;
}