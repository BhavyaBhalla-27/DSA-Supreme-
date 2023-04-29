#include<iostream>
#include<deque>
using namespace std;
int main(){
    // Creation
    deque<int>d;
    d.push_front(5);
    d.push_front(10);
    d.push_back(20);
    d.push_back(30);
    // Size
    cout<<"Size = "<<d.size()<<endl;
    d.pop_front();
    cout<<"Size = "<<d.size()<<endl;
    d.pop_front();
    cout<<"Size = "<<d.size()<<endl;
    // Checking front and rear
    cout<<"Front = "<<d.front()<<endl;
    cout<<"Rear = "<<d.back()<<endl;
    // Checking for empty
    if(d.empty()){
        cout<<"Empty"<<endl;
    }
    else{
        cout<<"Not empty";
    }
    return 0;
}