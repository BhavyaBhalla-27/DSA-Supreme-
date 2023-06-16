// https://leetcode.com/problems/longest-increasing-subsequence/description/

class Solution {
public:
    int solveRec(vector<int>&nums,int curr,int prev){
        // Base case
        if(curr >= nums.size())
            return 0;
        // include
        int include = 0;
        // no element included and hence simply include the element
        if(prev == -1 || nums[curr] > nums[prev]){
            include = 1 + solveRec(nums,curr+1,curr);
        }
        // exclude
        int exclude = 0 + solveRec(nums,curr+1,prev);
        int ans = max(include,exclude);
        return ans;
    }
    // Top down approach
    int solveTopDown(vector<int>&nums,int curr,int prev,vector<vector<int>>&dp){
        // Base case
        if(curr >= nums.size())
            return 0;
        // Step 3 : Check if answer exists already
        if(dp[curr][prev+1]!=-1){
            return dp[curr][prev+1];
        }
        // include
        int include = 0;
        // no element included and hence simply include the element
        if(prev == -1 || nums[curr] > nums[prev]){
            include = 1 + solveTopDown(nums,curr+1,curr,dp);
        }
        // exclude
        int exclude = 0 + solveTopDown(nums,curr+1,prev,dp);
        int ans = max(include,exclude);
        // Step 2 : Store ans in dp array
        // prev + 1 -> as -1 is not a valid index
        dp[curr][prev+1] = ans;
        return dp[curr][prev+1];
    }
    // Bottom up approach
    int solveTab(vector<int>&nums){
        int n = nums.size();
        // Step 1 : Create dp array
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        // Step 2 : Observe base case of top down -> already handled in initialization
        // Step 3 : Reverse the flow of top down
        for(int curr = n - 1;curr>=0;curr--){
            for(int prev = curr-1;prev>=-1;prev--){
                // include
                int include = 0;
                if(prev == -1 || nums[curr] > nums[prev]){
                    include = 1 + dp[curr+1][curr+1];
                }
                // exclude
                int exclude = 0 + dp[curr+1][prev+1];
                dp[curr][prev+1] = max(include,exclude);
            }
        }
        return dp[0][0];
    }
    // Space optimization
    int spaceOpt(vector<int>&nums){
        int n = nums.size();
        vector<int>currRow(n+1,0);
        vector<int>nextRow(n+1,0);
        // Step 2 : Observe base case of top down -> already handled in initialization
        // Step 3 : Reverse the flow of top down
        for(int curr = n - 1;curr>=0;curr--){
            for(int prev = curr-1;prev>=-1;prev--){
                // include
                int include = 0;
                if(prev == -1 || nums[curr] > nums[prev]){
                    include = 1 + nextRow[curr+1];
                }
                // exclude
                int exclude = 0 + nextRow[prev+1];
                currRow[prev+1] = max(include,exclude);
            }
            // Shift
            nextRow = currRow;
        }
        return nextRow[0];
    }
    // Optimal solution
    int solveOptimal(vector<int>&arr){
        if(arr.size() == 0){
            return 0;
        }
        vector<int>ans;
        ans.push_back(arr[0]);
        for(int i = 1;i<arr.size();i++){
            if(arr[i] > ans.back()){
                // include
                ans.push_back(arr[i]);
            }
            else{
                // overwrite
                // find index of just bigger element
                int index = lower_bound(ans.begin(),ans.end(),arr[i]) - ans.begin();
                ans[index] = arr[i];
            }
        }
        return ans.size();
    }
    int lengthOfLIS(vector<int>& nums) {
        int curr = 0;
        int prev = -1;
        // Recursive code
        // int ans = solveRec(nums,curr,prev);

        // Top Down approach
        // Step 1 : Create dp array
        // vector<vector<int>>dp(nums.size(),vector<int>(nums.size()+1,-1));
        // int ans = solveTopDown(nums,curr,prev,dp);

        // Bottom up approach
        // int ans = solveTab(nums);

        // Space optimization
        // int ans = spaceOpt(nums);

        // Optimal solution
        int ans = solveOptimal(nums);
        return ans;
    }
};