// https://leetcode.com/problems/reorganize-string/description/

class Solution {
public:
    string reorganizeString(string s) {
        // Step 1 : Create hash table
        int hash[26] = {0}; // Contains lowercase letters only
        for(int i = 0;i<s.length();i++){
            hash[s[i] - 'a']++;
        }
        // Step 2 : Try to place most occurent character
        char mostFreqChar;
        int max_freq = INT_MIN;
        for(int i = 0;i<26;i++){
            if(hash[i] > max_freq){
                max_freq = hash[i];
                mostFreqChar = i + 'a';
            }
        }
        int index = 0;
        while(max_freq > 0 && index < s.length()){
            s[index] = mostFreqChar;
            max_freq--;
            index = index + 2;
        }
        // Not possible case
        if(max_freq != 0){
            return ""; 
        }
        hash[mostFreqChar - 'a'] = 0;
        // Step 3 : Place rest of the characters
        for(int i = 0;i<26;i++){
            while(hash[i] > 0){
                // if index out of bound than update index to 1
                index = index >= s.size() ? 1 : index;
                s[index] = i + 'a';
                hash[i]--;
                index = index + 2;
            }
        }
        return s;
    }
};