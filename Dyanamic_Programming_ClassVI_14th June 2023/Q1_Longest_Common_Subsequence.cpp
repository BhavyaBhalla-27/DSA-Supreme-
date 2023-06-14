// https://leetcode.com/problems/longest-common-subsequence/description/

class Solution {
public:
    int solveRec(string a,string b,int i,int j){
        // Base Case (String completely traversed)
        if(i == a.length())
            return 0;
        if(j == b.length())
            return 0;
        // Match case
        if(a[i] == b[j]){
            return 1 + solveRec(a,b,i+1,j+1);
        }
        // Mismatch case
        else{
            return 0 + max(solveRec(a,b,i,j+1),solveRec(a,b,i+1,j));
        }
    }
    // Top down approach (Make sure strings are passed as by reference)
    int solveTopDown(string& a,string& b,int i,int j,vector<vector<int>>&dp){
        // Base Case (String completely traversed)
        if(i == a.length())
            return 0;
        if(j == b.length())
            return 0;
        // Step 3 : Check if answer already exists
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        // Match case
        int ans = 0;
        if(a[i] == b[j]){
            ans = 1 + solveTopDown(a,b,i+1,j+1,dp);
        }
        // Mismatch case
        else{
            ans = 0 + max(solveTopDown(a,b,i,j+1,dp),solveTopDown(a,b,i+1,j,dp));
        }
        // Step 2 : Store answer in dp array
        dp[i][j] = ans;
        return dp[i][j];
    }
    // Bottom up approach
    int solveTab(string a,string b){
        // Step 1 : Create dp array
        vector<vector<int>>dp(a.length()+1,vector<int>(b.length()+1,0));
        // Step 2 :  Observe base case
        // Already initialized to 0
        // Step 3 : Reverse the flow of top down
        for(int i = a.length()-1;i>=0;i--){
            for(int j = b.length()-1;j>=0;j--){
               // Match case
                int ans = 0;
                if(a[i] == b[j]){
                    ans = 1 + dp[i+1][j+1];
                }
                // Mismatch case
                else{
                    ans = 0 + max(dp[i][j+1],dp[i+1][j]);
                } 
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }
    int spaceOpt(string a,string b){
        vector<int>curr(b.length()+1,0);
        vector<int>next(b.length()+1,0);
        for(int i = a.length()-1;i>=0;i--){
            for(int j = b.length()-1;j>=0;j--){
               // Match case
                int ans = 0;
                if(a[i] == b[j]){
                    ans = 1 + next[j+1];
                }
                // Mismatch case
                else{
                    ans = 0 + max(curr[j+1],next[j]);
                } 
                curr[j] = ans;
            }
            // shift
            next = curr;
        }
        return next[0];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int i = 0;
        int j = 0;
        // Recursive code

        // return solveRec(text1,text2,i,j);
        
        // Top down solution
        // vector<vector<int>>dp(text1.length(),vector<int>(text2.length(),-1));
        // int ans = solveTopDown(text1,text2,i,j,dp);
        
        // Bottom up approach
        // int ans = solveTab(text1,text2);

        // Space optimization
        int ans = spaceOpt(text1,text2);
        return ans;
    }
};