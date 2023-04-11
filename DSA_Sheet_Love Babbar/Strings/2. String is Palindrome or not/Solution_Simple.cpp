#include<iostream>
using namespace std;
bool isPalindrome(string &s){
    // Maintaining 2 pointer
    int i = 0;
    int j = s.length() - 1;
    // Run a loop
    while(i<=j){
        if(s[i] != s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
int main(){
    string s = "abcba";
    if(isPalindrome(s)){
        cout<<"It is a palindrome"<<endl;
    }
    else{
        cout<<"It is not a palindrome"<<endl;
    }
    return 0;
}