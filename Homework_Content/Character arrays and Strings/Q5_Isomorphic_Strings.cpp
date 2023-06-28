// https://leetcode.com/problems/isomorphic-strings/description/


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // Mapping of characters from string s to string t
        int hash[256] = {0};
        bool charMapped[256] = {0};
        for(int i = 0;i<s.length();i++){
            // No mapping
            if(hash[s[i]] == 0 && charMapped[t[i]] == 0){
                // Create a mapping
                hash[s[i]] = t[i]; 
                // Mark that curr character of t is mapped
                charMapped[t[i]] = true;
            }
        }
        // Now using the hash make a string and then compare this string with t
        for(int i = 0;i<s.length();i++){
            if(hash[s[i]] != t[i])
                return false;
        }
        return true;
    }
};