// https://leetcode.com/problems/minimum-size-subarray-sum/description/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0;
        int j = 0;
        int sum = 0;
        int len = INT_MAX;
        while(j<nums.size()){
            // include current number
            sum = sum + nums[j];
            // Sum of one window is ready
            while(sum>=target){
                len = min(len,j-i+1);
                sum = sum - nums[i];
                i++;
            }
            j++;
        }
        if(len == INT_MAX){
            return 0;
        }
        return len;
    }
};

