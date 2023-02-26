#include<iostream>
using namespace std;
string removeDuplicates(string &s){
    string ans = ""; // Initially ans string is empty
    int i = 0;
    while(i<s.length()){ // Traverse the whole input string
        if(ans.length() > 0){ // Check whether there is any character in ans string or not
            if(ans[ans.length() - 1] == s[i]){ // Last element added is equal to current element of input string -> Adjacent element found 
            ans.pop_back(); // Remove from ans as it is duplicate
            }
        else{
            ans.push_back(s[i]); // Simply add character from input string 
        }
        }
        else{
            ans.push_back(s[i]); // Simply add character from input string if ans is empty
        }
        i++; // Go to next character of the input string
    }
    return ans; // Simply return ans
}
int main(){
    string s = "abbaca";
    string ans = removeDuplicates(s);
    cout<<ans;
    return 0;
}