// 

class Solution {
public: 
    // Recursion code
    // n-> represents the index of current house
    int solveRec(vector<int>&nums,int n){
        // Base Case
        if(n < 0){
            return 0;
        }
        if(n == 0){
            return nums[0];
        }
        // Include case
        int include = nums[n] + solveRec(nums,n-2);
        // Exclude case
        int exclude = 0 + solveRec(nums,n-1);
        return max(include,exclude);
    }   
    // Top down approach
    int solveTopDown(vector<int>&nums,int n,vector<int>&dp){
        // Base Case
        if(n < 0){
            return 0;
        }
        if(n == 0){
            return nums[0];
        }
        // Step 3 : Check if answer exists already
        if(dp[n] != -1)
            return dp[n];
        // Include case
        int include = nums[n] + solveTopDown(nums,n-2,dp);
        // Exclude case
        int exclude = 0 + solveTopDown(nums,n-1,dp);
        // Step 2 : Include in dp array
        dp[n] = max(include,exclude);
        return dp[n];
    }
    // Bottom up approach
    int solveTab(vector<int>&nums,int n){
        // Step 1 : Create dp array
        vector<int>dp(n+1,0);
        // Step 2 : Observe base case of top down
        dp[0] = nums[0];
        // Step 3 : Reverse flow of top down 
        for(int i = 1;i<=n;i++){
            int temp = 0;
            if(i-2>=0){
                temp = dp[i-2];
            }
            int include = temp + nums[i];
            int exclude = dp[i-1] + 0;
            dp[i] = max(include,exclude);
        }
        return dp[n];
    }
    // Space optimization
    int spaceOpt(vector<int>&nums,int n){
        int prev2 = 0;
        int prev1 = nums[0];
        int curr = 0;
        for(int i = 1;i<=n;i++){
            int temp = 0;
            if(i-2>=0){
                temp = prev2;
            }
            int include = temp + nums[i];
            int exclude = 0 + prev1;
            curr = max(include,exclude);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        // Recursive code

        // int n = nums.size() - 1;    
        // int ans = solveRec(nums,n);
        // return ans;

        // Top down approach
        // Step 1 : Create dp array
        // int n = nums.size() - 1;
        // vector<int>dp(n+1,-1);
        // int ans = solveTopDown(nums,n,dp);
        // return ans;

        // Bottom up approach
        // int n = nums.size() - 1;
        // return solveTab(nums,n);

        // Space optimization
        int n = nums.size() - 1;
        return spaceOpt(nums,n);
    }
};