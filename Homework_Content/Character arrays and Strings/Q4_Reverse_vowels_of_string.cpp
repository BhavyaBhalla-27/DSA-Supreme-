// https://leetcode.com/problems/reverse-vowels-of-a-string/description/

class Solution {
public:
    bool isVowel(char ch){
        // Converting upper case to lower case if any
        if(ch >= 'A' && ch<='Z')
            ch = ch + 'a' - 'A';
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch =='u')
            return true;
        return false;
    }
    string reverseVowels(string s) {
        int i = 0;
        int j = s.length() - 1;
        while(i<=j){
            if(isVowel(s[i]) && isVowel(s[j]))
                swap(s[i++],s[j--]);
            if(!isVowel(s[i]))
                i++;
            else if(!isVowel(s[j]))
                j--;
        }
        return s;
    }
};