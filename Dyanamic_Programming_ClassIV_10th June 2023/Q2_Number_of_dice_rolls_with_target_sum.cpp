// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/description/

class Solution {
public:
    long long int MOD = 1000000007;
    int solveRec(int n,int k,int target){
        // Base case
        if(n<0) 
            return 0;
        if(n == 0 && target == 0)
            return 1;
        if(n == 0 && target != 0)
            return 0;
        if(n!=0 && target == 0)
            return 0;
        long long int ans = 0;
        for(int i = 1;i<=k;i++){
            ans = ans + solveRec(n-1,k,target-i);
        }
        return ans;
    }
    long long int solveTopDown(int n,int k,int target,vector<vector<long long int>>&dp){
         // Base case
        if(n<0) 
            return 0;
        if(n == 0 && target == 0)
            return 1;
        if(n == 0 && target != 0)
            return 0;
        if(n!=0 && target == 0)
            return 0;
        // Step 3 : Check if answer exists
        if(dp[n][target]!=-1){
            return dp[n][target];
        }
        long long int ans = 0;
        for(int i = 1;i<=k;i++){
            long long int recAns = 0;
            if(target - i >= 0){
                recAns = solveTopDown(n-1,k,target-i,dp);
            }
            recAns = recAns % MOD;
            ans = ans % MOD;
            ans = (ans + recAns)%MOD;
        }
        // Step 2 : Store in dp array
        dp[n][target] = ans;
        return dp[n][target];
    }
    // Bottom up approach
    int solveTab(int n,int k,int target){
        // Step 1 : Create the dp array
        vector<vector<long long int>>dp(n+1,vector<long long int>(target+1,0));
        // Step 2 : Observe the base case of top down
        dp[0][0] = 1;
        // Step 3 : Reverse the flow of top down
        for(int index = 1;index<=n;index++){
            for(int t = 1;t<=target;t++){
                long long int ans = 0;
                for(int i = 1;i<=k;i++){
                    long long int recAns = 0;
                    if(t - i >= 0){
                        recAns = dp[index-1][t-i];
                    }
                    ans = (ans%MOD + recAns%MOD)%MOD;
                    }
                    dp[index][t] = ans;
                }
        }
        return dp[n][target];
    }
    // Space optimization
    int spaceOptimization(int n,int k,int target){
        vector<int>prev(target+1,0);
        vector<int>curr(target+1,0);
        // Step 2 : Observe the base case of top down
        prev[0] = 1;
        // Step 3 : Reverse the flow of top down
        for(int index = 1;index<=n;index++){
            for(int t = 1;t<=target;t++){
                long long int ans = 0;
                for(int i = 1;i<=k;i++){
                    long long int recAns = 0;
                    if(t - i >= 0){
                        recAns = prev[t-i];
                    }
                    ans = (ans%MOD + recAns%MOD)%MOD;
                    }
                    curr[t] = ans;
                }
                // Shift logic
                prev = curr;
        }
        return prev[target];
    }
    int numRollsToTarget(int n, int k, int target) {
        // Recursion solution

        // return solveRec(n,k,target);

        // Top down solution
        // Step 1 : Create 2D array
        // vector<vector<long long int>>dp(n+1,vector<long long int>(target+1,-1));
        // return solveTopDown(n,k,target,dp);


        // Bottom up solution
        // int ans = solveTab(n,k,target);

        // Space optimization solution
        int ans = spaceOptimization(n,k,target);
        return ans;
    }
};
