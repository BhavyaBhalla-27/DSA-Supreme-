#include<iostream>
using namespace std;
class CircularQueue{
    public:
    int size;
    int *arr;
    int front;
    int rear;
    // Constructor
    CircularQueue(int n){
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }
    void push(int data){
        // Queue Full 
        if((front == 0 && rear == size-1) || (rear == (front-1)%(size-1))){
            cout<<"Full queue";
        }
        // Single element case
        else if(front == -1){
            front = rear = 0;
            arr[rear] = data;
        }
        // Circular nature
        else if(front!=0 && rear == size-1){
            rear = 0;
        }
        // Normal flow
        else{
            arr[rear] = data;
            rear++;
        }
    }
    void pop(){
        // Empty check
        if(front == -1){
            cout<<"Queue is empty"<<endl;
        }
        // Single element
        else if(front == rear){
            arr[front] = -1;
            front = rear = -1;
        }
        // Circular nature
        else if(front == size-1){
            front = 0;
        }
        // Normal flow
        else{
            front++;
        }
    }
};
int main(){
    
}