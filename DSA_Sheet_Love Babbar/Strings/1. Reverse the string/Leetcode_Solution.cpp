// https://leetcode.com/problems/reverse-string/

class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0; // First Index
        int j = s.size() - 1; // Last Index
        while(i<=j){
            swap(s[i],s[j]); // Swap the valuse
            i++; // Increment the value of i
            j--; // Decrement the value of j.
        }
    }
};