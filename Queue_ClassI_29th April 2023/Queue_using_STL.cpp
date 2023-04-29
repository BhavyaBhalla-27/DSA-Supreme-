#include<iostream>
#include<queue>
using namespace std;
int main(){
    // Creation step
    queue<int>q;
    // Insertion
    q.push(5);
    q.push(10);
    q.push(15);
    q.push(20);
    // Checking size
    cout<<"Size of queue = "<<q.size()<<endl;
    // Removal 
    q.pop(); // 5 is removed
    cout<<"Size of queue = "<<q.size()<<endl;
    // Checking empty 
    if(q.empty()){
        cout<<"Empty"<<endl;
    }
    else{
        cout<<"Not empty"<<endl;
    }
    // checking front element
    cout<<"Front element = "<<q.front()<<endl;
    
    return 0;
}