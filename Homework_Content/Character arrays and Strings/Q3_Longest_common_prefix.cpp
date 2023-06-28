// https://learn.thecodehelp.in/s/courses/63ac9183e4b0f1067f1b7b32/take

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int i = 0;
        while(true){
            char curr = 0;
            for(auto str : strs){
                // Checking for out of bound
                if(i>=str.size()){
                    curr = 0;
                    break;
                }
                if(curr == 0)   
                    curr = str[i];
                else if(str[i] != curr){
                    // curr is set to 0 for getting out of infinite loop
                    curr = 0;
                    break;
                }
            }
            
            if(curr == 0){
                break;
            }
            ans.push_back(curr);
            i++;
        }
        return ans;
    }
};