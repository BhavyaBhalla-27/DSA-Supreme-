// https://leetcode.com/problems/partition-equal-subset-sum/

class Solution {
public:
    bool solveRec(int index,vector<int>&nums,int target){
        // Base case
        if(index >= nums.size()){
            return false;
        }
        if(target < 0){
            return false;
        }
        if(target == 0){
            return true;
        }
        // include
        bool include = solveRec(index+1,nums,target-nums[index]);
        // exclude
        bool exclude = solveRec(index+1,nums,target);
        return (include || exclude);
    }
    // Top down approach
    bool solveTopDown(int index,vector<int>&nums,int target,vector<vector<int>>&dp){
        // Base case
        if(index >= nums.size()){
            return false;
        }
        if(target < 0){
            return false;
        }
        if(target == 0){
            return true;
        }
        // Step 3 : Check if answer already exists
        if(dp[index][target]!=-1){
            return dp[index][target];
        }
        // include
        bool include = solveTopDown(index+1,nums,target-nums[index],dp);
        // exclude
        bool exclude = solveTopDown(index+1,nums,target,dp);
        // Step 2 : Store answer in dp array
        dp[index][target] = include||exclude;
        return dp[index][target];
    }
    // Bottom up approach
    bool solveTab(vector<int>&nums,int target){
        int n = nums.size();
        // Step 1 : Create dp array
        vector<vector<int>>dp(nums.size()+1,vector<int>(target+1,0));
        // Step 2 : Observe base case of top down
        for(int i = 0;i<nums.size();i++){
            dp[i][0] = 1;
        }
        // Step 3 : Reverse the flow of top down
        for(int index = n-1;index>=0;index--){
            for(int t = 1;t<=target;t++){
                bool include = 0;
                if(t-nums[index]>=0){
                    include = dp[index+1][t-nums[index]];
                }
                bool exclude = dp[index+1][t];
                dp[index][t] = include || exclude;
            }
        }
        // As we are coming from n to 0, and hence answer is stored in dp[0][target];
        return dp[0][target];
    }
    // Space optimization - 1
    bool spaceOptimization1(vector<int>&nums,int target){
        int n = nums.size();
        // Create 2 1D arrays
        vector<int>curr(target+1,0);
        vector<int>next(target+1,0);
        curr[0] = 1;
        next[0] = 1;
        for(int i = 0;i<nums.size();i++){
            next[0] = 1;
        }
        // Step 3 : Reverse the flow of top down
        for(int index = n-1;index>=0;index--){
            for(int t = 1;t<=target;t++){
                bool include = 0;
                if(t-nums[index]>=0){
                    include = next[t-nums[index]];
                }
                bool exclude = next[t];
                curr[t] = include || exclude;
            }
            // Shift logic (Going upwards)
            next = curr;
        }
        // As we are coming from n to 0, and hence answer is stored in dp[0][target];
        return curr[target];
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        // Find the sum of elements of array
        for(int i = 0;i<nums.size();i++){
            sum = sum + nums[i];
        }
        // Sum is odd then simply return false (Here I can do mistake)
        if(sum&1){
            return false;
        }
        // Find target
        int index = 0;
        int target = sum/2;
        // Recursive solution 

        // bool ans = solveRec(index,nums,target);

        // Top down solution
        // vector<vector<int>>dp(nums.size(),vector<int>(target+1,-1));
        // bool ans = solveTopDown(index,nums,target,dp);

        // Bottom up solution
        // bool ans = solveTab(nums,target);

        // Space optimization 1
        bool ans = spaceOptimization1(nums,target);
        return ans;
    }
};