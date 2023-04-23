#include<iostream>
using namespace std;
class Stack{
    public:
    int *arr;
    int top; // To access top element
    int size;
    Stack(int size){
        arr = new int[size];
        this->size = size;
        top = -1; // As 0 is valid index and -1 is not valid and will help in empty stack
    }
    // Functions
    void push(int data){
        if(size - top > 1){
            // Space available
            top++;
            arr[top] = data;
        }
        else{
            // Space not available
            cout<<"Stack overflow"<<endl;
        }
    }
    void pop(){
        // Stack empty
        if(top == -1){
            cout<<"Stack underflow"<<endl;
        }
        else{
            // Stack not empty and hence we can delete 
            top--;
        }
    }
    void getTop(){
        // Check stack is empty 
        if(top == -1){
            cout<<"Stack is empty"<<endl;
        }
        else{
            cout<<arr[top]<<endl;
        }
    }
    int getSize(){
        // Number of elements in stack is top + 1
        return top + 1;
    }
    bool isEmpty(){
        // Stack is empty condition
        if(top == -1){
            return true;
        }
        // Stack not empty
        return false;
    }
};
int main(){
    Stack s(10);
    // Insertion
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    // Printing stack
    while(!s.isEmpty()){
        s.getTop();
        s.pop();
    }
    // Checking size
    cout<<"Size of stack = "<<s.getSize()<<endl;
    // Checking empty or not
    if(s.isEmpty()){
        cout<<"Stack empty"<<endl;
    }
    else{
        cout<<"Stack is not empty"<<endl;
    }
    return 0;
}