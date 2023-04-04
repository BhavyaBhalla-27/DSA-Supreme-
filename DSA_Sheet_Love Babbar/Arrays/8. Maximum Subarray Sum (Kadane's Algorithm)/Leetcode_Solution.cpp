// https://leetcode.com/problems/maximum-subarray/description/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Initial steps
        int sum = 0;
        int maxi = nums[0];
        // Traverse the array
        for(int i = 0;i<nums.size();i++){
            // Step - 1 => 
            sum = sum + nums[i];
            // Step - 2 => 
            maxi = max(sum,maxi);
            // Step - 3 =>
            if(sum<0){
                sum = 0;
            }
        }
        return maxi;
    }
};