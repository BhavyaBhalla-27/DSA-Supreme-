// https://leetcode.com/problems/guess-number-higher-or-lower-ii/description/

class Solution {
public:
    int solveRec(int start,int end){
        // Base Case -> Invalid range
        if(start>=end){
            return 0; 
        }
        int ans = INT_MAX;
        for(int i = start;i<=end;i++){
            // Considering the current penalty and then trying to fetch answer from left and right  
            ans = min(ans,i+max(solveRec(start,i-1),solveRec(i+1,end)));
        }
        return ans;
    }
    // Top down approach
    int solveTopDown(int start,int end,vector<vector<int>>&dp){
        // Base Case -> Invalid range
        if(start>=end){
            return 0; 
        }
        // Step 3 : Check whether answer exists
        if(dp[start][end]!=-1)
            return dp[start][end];
        int ans = INT_MAX;
        for(int i = start;i<=end;i++){
            // Considering the current penalty and then trying to fetch answer from left and right  
            ans = min(ans,i+max(solveTopDown(start,i-1,dp),solveTopDown(i+1,end,dp)));
        }
        // Step 2 : Store the answer in dp array
        dp[start][end] = ans;
        return dp[start][end];
    }
    // Bottom up approach 
    int solveTab(int n){
        // Step 1 : Create dp array
        vector<vector<int>>dp(n+2,vector<int>(n+2,0));
        // Step 2 : Observe base case of top down
        // Handled in step 3
        // Step 3 : Reverse the flow of top down
        for(int start = n ; start>=1;start--){
            for(int end = 1;end<=n;end++){
                // Base case handled
                if(start >= end){
                    continue;
                }
                else{
                    int ans = INT_MAX;
                    for(int i = start;i<=end;i++){
                        ans = min(ans,i+max(dp[start][i-1],dp[i+1][end]));
                    }
                    dp[start][end] = ans;
                }
            }
        }
        // As we have made call from 1 to n in top down
        return dp[1][n];
    }
    int getMoneyAmount(int n) {
        // Recursive code
        // int ans = solveRec(1,n);
        
        // Top down approach
        // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        // int ans = solveTopDown(1,n,dp);

        // Bottom up approach
        int ans = solveTab(n);
        return ans;
    }
};