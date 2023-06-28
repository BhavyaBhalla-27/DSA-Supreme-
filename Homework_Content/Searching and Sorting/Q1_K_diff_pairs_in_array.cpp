// https://leetcode.com/problems/k-diff-pairs-in-an-array/description/

class Solution {
public:
    // binary search used in method - 3
    bool binarySearch(vector<int>&nums,int start,int end,int target){
        int ans = -1;
        int mid = start + (end - start)/2;
        while(start<=end){
            // Case 1
            if(nums[mid] == target){
                return true;
            }
            // Case 2
            else if(nums[mid] > target){
                // search in left
                end = mid - 1;
            }
            // Case 3
            else{
                // search in right
                start = mid + 1;
            }
            // update mid
            mid = start + (end-start)/2;
        }
        return false;
    }
    int findPairs(vector<int>& nums, int k) {
        // Method - 2
        // sort(nums.begin(),nums.end());
        // int i = 0;
        // int j = 1;
        // set<pair<int,int>>ans;
        // while(j<nums.size()){
        //     // Calculate difference
        //     int difference = nums[j] - nums[i];
        //     // Case 1
        //     if(difference == k){
        //         ans.insert({nums[i],nums[j]});
        //         i++;
        //         j++;
        //     }
        //     // Case 2
        //     else if(difference > k){
        //         i++;
        //     }
        //     // Case 3
        //     else{
        //         j++;
        //     }
        //     // To handle case i != j
        //     if(i == j)
        //         j++;
        // }
        // return ans.size();

        // Method - 3
        sort(nums.begin(),nums.end());
        set<pair<int,int>>ans;
        for(int i = 0;i<nums.size()-1;i++){
            int secondElement = nums[i] + k;
            if(binarySearch(nums,i+1,nums.size()-1,secondElement)){
                ans.insert({nums[i],secondElement});
            }
        }
        return ans.size();
    }
};