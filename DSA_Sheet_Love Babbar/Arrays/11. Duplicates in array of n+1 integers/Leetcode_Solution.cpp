// https://leetcode.com/problems/find-the-duplicate-number/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Simply sorting the array
        sort(nums.begin(),nums.end());
        int ans = nums[0]; // Initial guess
        for(int i = 1;i<nums.size();i++){ // Just comparing adjacent elements
            if(nums[i-1] == nums[i]){
                ans = nums[i];
                break;
            }
        }
        return ans;
    }
};