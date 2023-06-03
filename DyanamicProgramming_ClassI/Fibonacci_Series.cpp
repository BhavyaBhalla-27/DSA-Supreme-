class Solution {
public:
    int recSolve(int n){
        // Base case
        if(n == 1 || n == 0){
            return n;
        }
        int ans = recSolve(n-1)+recSolve(n-2);
        return ans;
    }
    int topDownSolve(int n,vector<int>&dp){
        // Base case
        if(n == 1 || n == 0){
            return n;
        }
        // Step 3 : check if already calculate
        if(dp[n]!=-1){
            return dp[n];
        }
        // Step 2 : replace ans with dp[n]
        dp[n] = topDownSolve(n-1,dp)+topDownSolve(n-2,dp);
        return dp[n];
    }
    int BottomUpSolve(int n){
        // step 1 : create dp array
        vector<int>dp(n+1,-1);
        // step 2 : observe base case in top down solution
        dp[0] = 0;
        if(n == 0){
            return dp[0];
        }
        dp[1] = 1;
        if(n == 1){
            return dp[1];
        }
        // step 3 : observe the flow in top down (simply reverse) 
        // We were going from n to 2 in top down, simply go from 2 to n
        for(int i =2;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
    int spaceOptSolve(int n){
        int prev2 = 0;
        int prev1 = 1;
        if(n == 0)
            return prev2;
        if(n == 1)
            return prev1;
        int curr;
        for(int i = 2;i<=n;i++){
            curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }
    int fib(int n) {
        // int ans = recSolve(n);
        // return ans;

        // Top down approach

        // Step 1 : Create DP array
        // vector<int>dp(n+1,-1);
        // int ans = topDownSolve(n,dp);
        // return ans;

        // Bottom up approach
        // int ans = BottomUpSolve(n);
        // return ans;
        
        // Space optimization
        int ans = spaceOptSolve(n);
        return ans;
    }
};