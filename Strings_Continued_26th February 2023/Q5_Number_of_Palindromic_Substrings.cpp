#include<iostream>
using namespace std;
int expandAroundIndex(string s,int i,int j){
    int count = 0;
    while(i>=0 && j<s.length() && s[i]==s[j]){
        count++;
        i--;
        j++;
    }
    return count;
}
int countPalindromicSubstrings(string s){
    int count = 0;
    int n = s.length();
    for(int i = 0;i<n;i++){
        // Odd length substring
        int oddAns = expandAroundIndex(s,i,i);
        count = count + oddAns;
        // Even length substring
        int evenAns = expandAroundIndex(s,i,i+1);
        count = count + evenAns;
    }
    return count;
}
int main(){
    string s = "aaa";
    int ans = countPalindromicSubstrings(s);
    cout<<ans;
    return 0;
}