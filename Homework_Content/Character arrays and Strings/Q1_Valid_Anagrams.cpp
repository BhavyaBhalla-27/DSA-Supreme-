// https://leetcode.com/problems/valid-anagram/description/

class Solution {
public:
    bool isAnagram(string s, string t) {
        // Method - 1 (Sorting)
        // sort(s.begin(),s.end());
        // sort(t.begin(),t.end());
        // return s==t;

        // Method - 2 (Counting)
        int count1[26] = {0}; // Question says that string contains lower case alphabets only
        // Preparing frequency table for s
        for(int i = 0;i<s.length();i++){
            count1[s[i] - 'a']++;
        }
        // Checking whether table is same or not -> Count in count1 should be zero
        for(int i = 0;i<t.length();i++){
            count1[t[i] - 'a']--;
        }
        for(int i = 0;i<26;i++){
            if(count1[i] != 0){
                return false;
            }
        }
        return true;
    }
};