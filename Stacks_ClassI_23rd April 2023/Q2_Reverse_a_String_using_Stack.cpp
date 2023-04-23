#include<iostream>
#include<stack>
using namespace std;
void reverse(string str){
    stack<char>s;
    for(int i = 0;i<str.length();i++){
        s.push(str[i]);
    }
    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }

}
int main(){
    string str = "bhavya";
    reverse(str);
    return 0;
}