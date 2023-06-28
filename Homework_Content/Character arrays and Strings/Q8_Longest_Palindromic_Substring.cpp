// https://leetcode.com/problems/longest-palindromic-substring/description/

class Solution {
public:
    bool isPalindrome(string &s,int i,int j){
        // i-> start
        // j-> end
        while(i<=j){
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        string ans = "";
        // Find out all the substrings and check if it is a palindrome or not
        for(int i = 0;i<s.size();i++){
            for(int j = i;j<s.size();j++){
                if(isPalindrome(s,i,j)){
                    string t = s.substr(i,j-i+1);
                    if(t.length() > ans.length())
                        ans = t;
                }
            }
        }
        return ans;
    }
};