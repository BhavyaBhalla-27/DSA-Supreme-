#include<iostream>
#include<string.h>
using namespace std;
bool checkPalindrome(char name[]){
    int s = 0;
    int e = strlen(name) - 1;
    while(s<=e){
        if(name[s] != name[e]){
            return false;
        }
        else{
            s++;
            e--;
        }
    }
    return true;
}
int main(){
    char name[100] = "racecar";
    if(checkPalindrome(name)){
        cout<<"Palindrome";
    }
    else{
        cout<<"Not Palindrome";
    }
    return 0;
}