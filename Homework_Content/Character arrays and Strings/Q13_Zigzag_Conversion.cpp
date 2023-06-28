// https://leetcode.com/problems/zigzag-conversion/description/

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        vector<string>zigzag(numRows);
        int i = 0;
        int row = 0;
        int direction = 1; // 1 -> Top to Bottom
        // direction = 0 -> Bottom to top
        while(1){
            if(direction){
                while(row < numRows && i < s.length()){
                    zigzag[row++].push_back(s[i++]);
                }
                row = numRows - 2;
            }
            else{
                while(row>=0  && i < s.length()){
                        zigzag[row--].push_back(s[i++]);
                }
                row = 1;
            }
            if(i>=s.length())
                break;
            direction = !direction;
        }
        string ans = "";
        for(int i = 0;i<zigzag.size();i++){
            ans = ans + zigzag[i];
        }
        return ans;
    }   
};