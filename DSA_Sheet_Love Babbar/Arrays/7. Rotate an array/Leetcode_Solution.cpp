// https://leetcode.com/problems/rotate-array/description/

// Clockwise rotation by k steps

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k>nums.size()){
            k = k % nums.size(); // To bring back the k between 0 to end index
        }
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin() + k);
        reverse(nums.begin() + k,nums.end());
    }
};