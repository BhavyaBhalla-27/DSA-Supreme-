#include<iostream>
#include<stack>
using namespace std;
void solve(stack<int>&s,int target){
    // Base case -> stack empty or not
    if(s.empty()){
        s.push(target); // simply push the target
        return;
    }
    // Fetch top element
    int topElement = s.top();
    s.pop();
    // recursive call for next element
    solve(s,target);
    // backtracking
    s.push(topElement);
}
void reverseStack(stack<int>&s){
    // Base case -> stack empty and cant reverse
    if(s.empty()){
        return;
    }
    // Handle just one case
    int target = s.top();
    s.pop();
    // Reverse the stack
    reverseStack(s);
    // Insert at Bottom
    solve(s,target);
}
int main(){
    stack<int>s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    // Before reversing
    // while(!s.empty()){
    //     cout<<s.top()<<" ";
    //     s.pop();
    // }
    cout<<endl;
    reverseStack(s);
    // After reversing
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}