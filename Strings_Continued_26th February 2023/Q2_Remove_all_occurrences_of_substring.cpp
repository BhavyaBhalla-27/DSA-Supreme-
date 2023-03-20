#include<iostream>
using namespace std;
string removeOccurrence(string s,string part){
    int pos = s.find(part); // Find the index of first occurrence of the part string in input string
    while(pos!=string::npos){ // Search until part is present in the input string
        s.erase(pos,part.length()); // Remove the part from the string
        pos = s.find(part); // Update pos and again find part. If part is not present then pos will have npos value
    }
    return s; // Simply return string after removing all the parts in the input string
}
int main(){
    string s = "daabcbaabcbc";
    string part = "abc";
    string ans = removeOccurrence(s,part);
    cout<<ans;
    return 0;
}