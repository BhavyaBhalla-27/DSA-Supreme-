// https://leetcode.com/problems/largest-number/description/

class Solution {
public:
    static bool mycomp(string a,string b){
        string t1 = a + b;
        string t2 = b + a;
        return t1 > t2;
    }
    string largestNumber(vector<int>& nums) {
        vector<string>snums;
        for(auto n : nums){
            snums.push_back(to_string(n));
        }
        // Sorting according to comparator function
        sort(snums.begin(),snums.end(),mycomp);
        string ans = "";
        for(int i = 0;i < snums.size();i++){
            ans = ans + snums[i];
        }
        // Here I will do mistake (If first character is 0, this means largest number is 0 and hence all will be 0)
        if(ans[0] == '0'){
            ans = "0";
        }
        return ans;
    }
};