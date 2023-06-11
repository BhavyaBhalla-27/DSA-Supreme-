// https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/description/

class Solution {
public:
    int solveRec(vector<int>&arr,map<pair<int,int>,int>&maxi,int left,int right){
        // Base case
        if(left == right){
            return 0; // Leaf node and we don't have to store the sum of leaf nodes
        }
        int ans = INT_MAX;
        for(int i = left;i<right;i++){
            ans = min(ans,maxi[{left,i}]*maxi[{i+1,right}] + solveRec(arr,maxi,left,i) + solveRec(arr,maxi,i+1,right));
        }
        return ans;
    }
    // Top down approach
    int solveTopDown(vector<int>&arr,map<pair<int,int>,int>&maxi,int left,int right,vector<vector<int>>&dp){
        // Base case
        if(left == right){
            return 0; // Leaf node and we don't have to store the sum of leaf nodes
        }
        // Step 3 : Check if answer already exists
        if(dp[left][right] != -1){
            return dp[left][right];
        }
        int ans = INT_MAX;
        for(int i = left;i<right;i++){
            ans = min(ans,maxi[{left,i}]*maxi[{i+1,right}] + solveTopDown(arr,maxi,left,i,dp) + solveTopDown(arr,maxi,i+1,right,dp));
        }
        // Step 2 : Store answer in dp array
        dp[left][right] = ans;
        return dp[left][right];
    }
    // Bottom up approach
    int solveTab(vector<int>&arr,map<pair<int,int>,int>&maxi){
        int n = arr.size();
        // Step 1 : Create dp array
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        // Step 2 : Observe base case in top down
        // Already initialized to 0.
        // Step 3 : Reverse the flow of top down
        for(int left = n - 1;left>=0;left--){
            for(int right = 0;right<=n-1;right++){
                if(left>=right)
                    continue;
                else{
                    int ans = INT_MAX;
                    for(int i = left;i<right;i++){
                        ans = min(ans,maxi[{left,i}]*maxi[{i+1,right}] + dp[left][i] + dp[i+1][right]);
                    }
                    dp[left][right] = ans;
                }
            }
        }
        // See top down call is 0 to n-1
        return dp[0][n-1];
    }
    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int,int>,int>maxi;
        // Pre-computation (Storing maximum value for all possible range)
        for(int i = 0;i<arr.size();i++){
            maxi[{i,i}] = arr[i];
            for(int j = i+1;j<arr.size();j++){
                maxi[{i,j}] = max(arr[j],maxi[{i,j-1}]);
            }
        }
        int n = arr.size();
        // Recursive code

        // int ans = solveRec(arr,maxi,0,n-1);

        // Top down solution
        // Step 1 : Create dp array
        // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        // int ans = solveTopDown(arr,maxi,0,n-1,dp);

        // Bottom up solution
        int ans = solveTab(arr,maxi);
        return ans;
    }
};