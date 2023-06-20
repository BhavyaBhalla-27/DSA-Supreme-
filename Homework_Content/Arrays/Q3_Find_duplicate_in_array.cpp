// https://leetcode.com/problems/find-the-duplicate-number/description/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Method - 1
        // int ans = 0;
        // sort(nums.begin(),nums.end());
        // for(int i = 1;i<nums.size();i++){
        //     if(nums[i] == nums[i-1]){
        //         ans = nums[i];
        //         break;
        //     }
        // }
        // return ans;

        // Method - 2
        // int ans = 0;
        // for(int i = 0;i<nums.size();i++){
        //     int index = abs(nums[i]);
        //     // already visited
        //     if(nums[index] < 0){
        //         ans = index;
        //     }
        //     // mark visited
        //     nums[index] = -1 * nums[index];
        // }
        // return ans;

        // Method - 3
        while(nums[0] != nums[nums[0]]){
            swap(nums[0],nums[nums[0]]);
        }
        return nums[0];
    }
};