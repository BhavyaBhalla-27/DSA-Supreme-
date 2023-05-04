#include<iostream>
#include<queue>
#include<stack>
using namespace std;
// Using stack
/*
void reverseQueue(queue<int>&q){
    stack<int>st;
    // Put all the elements into stack
    while(!q.empty()){
        int element = q.front();
        // Push the element
        st.push(element);
        // Pop the element from queue
        q.pop();
    }
    // Put all elements from stack to queue
    while(!st.empty()){
        int element = st.top();
        st.pop();
        q.push(element);
    }
}
*/

// Using recursion
void reverseQueue(queue<int>&q){
    // Base case
    if(q.empty()){
        return;
    }
    // Save front element
    int element = q.front();
    q.pop();
    // Recursive call
    reverseQueue(q);
    // Push element
    q.push(element);
}
int main(){
    queue<int>q;
    q.push(3);
    q.push(6);
    q.push(9);
    q.push(2);
    q.push(8);

    reverseQueue(q);
    // Printing queue
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}