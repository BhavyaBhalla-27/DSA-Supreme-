#include<iostream>
#include<stack> // Here we imported from STL
using namespace std;

int main(){
    // Creation of stack
    stack<int>s;
    // Insertion operation in stack
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    // Remove the element from stack
    s.pop(); // Removes 40
    // Check the topmost element in the stack
    cout<<"Topmost element = "<<s.top()<<endl;
    // Check size of the stack
    cout<<"Size of stack = "<<s.size()<<endl;
    // Check whether stack is empty or not
    if(s.empty()){
        cout<<"Stack is empty"<<endl;
    }
    else{
        cout<<"Stack is not empty"<<endl;
    }
    // Printing the stack
    while(!s.empty()){ // Print until stack is not empty
        cout<<s.top()<<endl;
        s.pop();
    }
    return 0;
}