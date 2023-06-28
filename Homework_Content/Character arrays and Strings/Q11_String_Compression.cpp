// https://leetcode.com/problems/string-compression/description/

class Solution {
public:
    int compress(vector<char>& s) {
        int index = 0;
        int count = 1;
        char prev = s[0];
        for(int i = 1;i<s.size();i++){
            if(s[i] == prev){
                count++;
            }
            else{
                s[index++] = prev;
                
                if(count>1){
                    // Handling case when count >= 10
                    int start = index;
                    while(count){
                        s[index++] = count%10 + '0';
                        count = count/10;
                    }
                    // Count obtained will be reverse and hence we need reverse to get correct count
                    reverse(s.begin() + start,s.begin() + index);
                }
                prev = s[i];
                count = 1;
            }
        }
        // ee condition in dry run
        s[index++] = prev;
        if(count>1){
            int start = index;
            while(count){
                s[index++] = count%10 + '0';
                count = count/10;
            }
            // Count obtained will be reverse and hence we need reverse to get correct count
            reverse(s.begin() + start,s.begin() + index);
        }
        return index;
    }
};