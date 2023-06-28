// https://leetcode.com/problems/group-anagrams/

class Solution {
public:
    std::array<int,256>hash(string s){
        std::array<int,256>hash = {0};
        for(int i = 0;i<s.length();i++){
            hash[s[i]]++;
        }
        return hash;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Method - 1 -> With sorting
        // map<string,vector<string>>mp;
        // for(auto str : strs){
        //     string s = str;
        //     sort(s.begin(),s.end());
        //     mp[s].push_back(str);
        // }
        // vector<vector<string>>ans;
        // for(auto it = mp.begin(); it!=mp.end();it++){
        //     ans.push_back(it->second);
        // }
        // return ans;

        // Method - 2 -> Without sorting
        map<std::array<int,256>,vector<string>>mp;
        for(auto str : strs){
            mp[hash(str)].push_back(str);
        }
        vector<vector<string>>ans;
        for(auto it = mp.begin();it!=mp.end();it++){
            ans.push_back(it->second);
        }
        return ans;
    }
}; 