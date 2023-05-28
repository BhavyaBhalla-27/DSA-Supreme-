#include<iostream>
#include<queue>
using namespace std;
int main(){
    cout<<"Max Heap"<<endl;
    // Creation of max heap
    priority_queue<int>pq;
    // Insertion in heap
    pq.push(23);
    pq.push(12);
    pq.push(67);
    pq.push(15);
    // Top element
    cout<<pq.top()<<endl;
    // Deleting the top element
    pq.pop();
    // Size of priority queue
    cout<<pq.size()<<endl;
    // Check empty or not
    if(pq.empty()){
        cout<<"empty "<<endl;
    }
    else{
        cout<<"not empty"<<endl;
    }
    cout<<"Min Heap"<<endl;
    // Creation of min heap
    priority_queue<int,vector<int>,greater<int>>p;
    // Insertion
    p.push(23);
    p.push(12);
    p.push(67);
    p.push(15);
    // Top element
    cout<<p.top()<<endl;
    // Deleting the top element
    p.pop();
    // Size of priority queue
    cout<<p.size()<<endl;
    // Check empty or not
    if(p.empty()){
        cout<<"empty "<<endl;
    }
    else{
        cout<<"not empty"<<endl;
    }
    return 0;
}