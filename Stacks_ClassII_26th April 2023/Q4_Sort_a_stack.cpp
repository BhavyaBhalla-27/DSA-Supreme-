#include<iostream>
#include<stack>
using namespace std;
void insertSorted(stack<int>&s,int target){
    // Base Case
    if(s.empty()){
        // simply insert as it will be sorted only
        s.push(target);
        return;
    }
    if(s.top()>= target){
        s.push(target);
        return;
    }
    // Normal case
    int topElement = s.top();
    s.pop();
    insertSorted(s,target);
    // Backtracking -> Push element while returning
    s.push(topElement);
}
void sortStack(stack<int>&s){
    // Base case
    if(s.empty()){
        return;
    }
    int topElement = s.top();
    s.pop();
    // Recursive call
    sortStack(s);
    // Backtracking
    insertSorted(s,topElement);
}
int main(){
    stack<int>s;
    s.push(9);
    s.push(5);
    s.push(3);
    s.push(11);
    s.push(7);
    sortStack(s);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}