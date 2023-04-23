#include<iostream>
using namespace std;
class Stack{
    public:
    int *arr;
    int top1;
    int top2;
    int size;
    Stack(int size){
        arr = new int[size];
        this->size = size;
        top1 = -1;
        top2 = size; 
    }
    // Functions
    void push1(int data){
        // Space not available
        if(top2 - top1 == 1){
            cout<<"Overflow";
        }
        // Space available
        else{
            top1++;
            arr[top1] = data;
        }
    }
    void push2(int data){
        // Space not available
        if(top2 - top1 == 1){
            cout<<"Overflow";
        }
        // Space available
        else{
            top2--;
            arr[top2] = data;
        }
    }
    void pop1(){
        // Stack empty
        if(top1 == -1){
            cout<<"Underflow";
        }
        // Stack not empty
        else{
            top1--;
        }
    }
    void pop2(){
        // Stack empty
        if(top2 == size){
            cout<<"Underflow";
        }
        // Stack not empty
        else{
            top2++;
        }
    }
    // Just for understanding purposes
    // void print(){
    //     for(int i = 0;i<size;i++){
    //         cout<<arr[i]<<" ";
    //     }
    // }
};
int main(){
    Stack s(6);
    s.push1(10);
    s.push2(20);
    s.push1(30);
    s.push2(40);
    s.push1(50);
    s.push2(60);
    // s.print();
    return 0;
}