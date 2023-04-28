// https://leetcode.com/problems/valid-parentheses/description/
#include<iostream>
#include<stack>
using namespace std;
bool isValid(string &s){
    stack<char>st;
    for(int i=0;i<s.length();i++){
        char ch = s[i];
        // Opening Bracket
        if(ch == '{' || ch == '(' || ch == '['){
            st.push(ch);
        }
        // Closing Bracket
        else{
            if(!st.empty()){ // Stack is not empty 
                char topCh = st.top();
                if(ch == ')' && topCh == '('){ // Matching bracket
                    // simply pop
                    st.pop();
                }
                else if(ch == '}' && topCh == '{'){ // Matching bracket
                    // simply pop
                    st.pop();
                }
                else if(ch == ']' && topCh == '['){ // Matching bracket
                    // simply pop
                    st.pop();
                }
                else{
                    // Brackets not matching 
                    return false;
                }
            }
            else{
                // Closing bracket is there but opening bracket is not there
                return false;
            }
        }
    }
    // Stack empty -> valid expression 
    if(st.empty()){
        return true;
    }
    return false;
    
}
int main(){
    string s = "(([]))[{()}]{()}";
    if(isValid(s)){
        cout<<"Valid Paranthesis";
    }
    else{
        cout<<"Not valid Paranthesis";
    }
    return 0;
}