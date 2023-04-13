// https://leetcode.com/problems/next-permutation/description/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // Step - 1 => Find the longest common prefix
        int n = nums.size();
        int index = -1;
        for(int i = n-2;i>=0;i--){
            if(nums[i] < nums[i+1]){
                index = i;
                break;
            }
        }
        // Handling the edge case
        if(index == -1){ // index does not change
            // Last permutaion and hence reverse and return
            reverse(nums.begin(),nums.end());
            return;
        }
        // Step - 2 => Swap the number at break point with element just greater
        for(int i = n - 1;i>=0;i--){
            if(nums[i]>nums[index]){
                swap(nums[i],nums[index]);
                break;
            }
        }
        // Step - 3 => Reverse the array after the breakpoint
        reverse(nums.begin() + index + 1,nums.end());
    }
};