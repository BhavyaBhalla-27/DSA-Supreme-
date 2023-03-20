#include<iostream>
using namespace std;
bool checkPalindrome(string s,int start,int end){
    while(start<=end){
        if(s[start] != s[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
}
bool palindrome(string s){
    int i = 0;
    int j = s.length() - 1;
    while(i<=j){
        if(s[i] != s[j]){ // We have to either remove i or j and check for palindrome 
            return checkPalindrome(s,i+1,j) || checkPalindrome(s,i,j-1); // Check for palindrome 
        }
        else{ // s[i] == s[j] case
            i++; // Simply increment i 
            j--; // Simply decrement j
        }
    }
    return true; // 0 removal case i.e. palindrome without any removal also
}
int main(){
    string s = "abca";
    if(palindrome(s)){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
    return 0;
}