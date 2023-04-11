#include<iostream>
using namespace std;
void reverseString(string &s){
    int i = 0;
    int j = s.length() - 1;
    while(i<=j){
        swap(s[i++],s[j--]);
    }
}
int main(){
    string s = "hello";
    reverseString(s);
    cout<<s<<endl;
    return 0;
}