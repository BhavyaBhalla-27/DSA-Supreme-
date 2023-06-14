// https://leetcode.com/problems/edit-distance/description/

class Solution {
public:
    int solveRec(string &a, string &b,int i,int j){
        // Base case
        if(i == a.length()){
            return b.length() - j;
        }
        if(j == b.length()){
            return a.length() - i;
        }
        // Match case
        int ans = 0;
        if(a[i] == b[j]){
            ans = solveRec(a,b,i+1,j+1);
        }
        // Mismatch case and hence operations to be peformed here
        else{
            int insert = 1 + solveRec(a,b,i,j+1);
            int deleted = 1 + solveRec(a,b,i+1,j);
            int replace = 1 + solveRec(a,b,i+1,j+1);
            ans = min(insert,min(deleted,replace));
        }
        return ans;
    }
    // Top down approach
    int solveTopDown(string &a, string &b,int i,int j,vector<vector<int>>&dp){
        // Base case
        if(i == a.length()){
            return b.length() - j;
        }
        if(j == b.length()){
            return a.length() - i;
        }
        // Step 3 : Check if answer already exists in dp
        if(dp[i][j]!=-1)
            return dp[i][j];
        // Match case
        int ans = 0;
        if(a[i] == b[j]){
            ans = solveTopDown(a,b,i+1,j+1,dp);
        }
        // Mismatch case and hence operations to be peformed here
        else{
            int insert = 1 + solveTopDown(a,b,i,j+1,dp);
            int deleted = 1 + solveTopDown(a,b,i+1,j,dp);
            int replace = 1 + solveTopDown(a,b,i+1,j+1,dp);
            ans = min(insert,min(deleted,replace));
        }
        // Step 2 : Store answer in dp array
        dp[i][j] = ans;
        return dp[i][j];
    }
    // Bottom up approach
    int solveTab(string &a,string &b){
        // Step 1 :  Create dp array
        vector<vector<int>>dp(a.length()+1,vector<int>(b.length()+1,0));
        // Step 2 : Observe base case of top down
        for(int j = 0;j<=b.length();j++){
            dp[a.length()][j] = b.length() - j;
        }
        for(int i = 0;i<=a.length();i++){
            dp[i][b.length()] = a.length() - i;
        }
        // Step 3 : Reverse the flow of top down
        for(int i = a.length()-1;i>=0;i--){
            for(int j = b.length()-1;j>=0;j--){
                // Match case
                int ans = 0;
                if(a[i] == b[j]){
                    ans = dp[i+1][j+1];
                }
                // Mismatch case and hence operations to be peformed here
                else{
                    int insert = 1 + dp[i][j+1];
                    int deleted = 1 + dp[i+1][j];
                    int replace = 1 + dp[i+1][j+1];
                    ans = min(insert,min(deleted,replace));
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }
    int spaceOpt(string &a,string &b){
        vector<int>curr(b.length()+1,0);
        vector<int>next(b.length()+1,0);
        // Step 2 : Observe base case of top down
        for(int j = 0;j<=b.length();j++){
            next[j] = b.length() - j;
        }
        // Step 3 : Reverse the flow of top down
        for(int i = a.length()-1;i>=0;i--){
            // Tricky step (Base case modified)
                curr[b.length()] = a.length() - i;
            for(int j = b.length()-1;j>=0;j--){
                // Match case
                int ans = 0;
                if(a[i] == b[j]){
                    ans = next[j+1];
                }
                // Mismatch case and hence operations to be peformed here
                else{
                    int insert = 1 + curr[j+1];
                    int deleted = 1 + next[j];
                    int replace = 1 + next[j+1];
                    ans = min(insert,min(deleted,replace));
                }
                curr[j] = ans;
            }
            // shift
            next = curr;
        }
        return next[0];
    }
    int minDistance(string word1, string word2) {
        int i = 0;
        int j = 0;
        // Recursive code
        // int ans = solveRec(word1,word2,i,j);
        
        // Top down solution
        // Step 1 : Create dp array
        // vector<vector<int>>dp(word1.length(),vector<int>(word2.length(),-1));
        // int ans = solveTopDown(word1,word2,i,j,dp);

        // Bottom up solution
        // int ans = solveTab(word1,word2);

        // Space optimization
        int ans = spaceOpt(word1,word2);
        return ans;
    }
};
