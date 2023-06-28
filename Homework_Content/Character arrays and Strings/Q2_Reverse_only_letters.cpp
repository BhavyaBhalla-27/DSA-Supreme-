// https://learn.thecodehelp.in/s/courses/63ac9183e4b0f1067f1b7b32/take

class Solution {
public:
    bool isAlphabet(char ch){
        if(ch >= 'A' && ch <='Z')
            return true;
        if(ch >= 'a' && ch <= 'z')
            return true;
        return false;
    }
    string reverseOnlyLetters(string s) {
        // 2 Pointer approach
        int i = 0;
        int j = s.length() - 1;
        while(i<=j){
            if(isAlphabet(s[i]) && isAlphabet(s[j])){
                // Swap condition
                swap(s[i++],s[j--]);
            }
            if(!isAlphabet(s[i]))
                i++;
            else if(!isAlphabet(s[j]))
                j--;
        }
        return s;
    }
};