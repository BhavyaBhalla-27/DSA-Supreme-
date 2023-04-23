#include<iostream>
#include<stack>
using namespace std;
void printMiddle(stack<int>&s,int &totalSize){
    // Empty case
    if(s.size() == 0){
        cout<<"No element in stack"<<endl;
        return;
    }
    // Base Case
    if(totalSize/2 + 1 == s.size()){
        cout<<"Middle element = "<<s.top();
        return;
    }
    // Operations
    int temp = s.top();
    s.pop();
    // recursive call
    printMiddle(s,totalSize);
    // backtracking
    s.push(temp);
}
int main(){
    stack<int>s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.push(70);
    int totalSize = s.size();
    printMiddle(s,totalSize);
    return 0;
}