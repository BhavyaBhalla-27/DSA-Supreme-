#include<iostream>
#include<vector>

using namespace std;
int solveRec(int n,int k){
    // Base case
    if(n == 1){
        return k;
    }
    if(n == 2){
        return k + k*(k-1);
    }
    // Recursive call
    int ans = (solveRec(n-2,k) + solveRec(n-1,k))*(k-1);
    return ans;
}

// Top down approach
int solveTopDown(int n,int k,vector<int>&dp){
    // Base case
    if(n == 1){
        return k;
    }
    if(n == 2){
        return k + k*(k-1);
    }
    // Step 3 : Check answer already exists
    if(dp[n]!=-1){
        return dp[n];
    }
    // Recursive call
    dp[n] = (solveRec(n-2,k) + solveRec(n-1,k))*(k-1);
    return dp[n];
}
// Bottom up approach
int solveTab(int n,int k){
    // Step 1 : Create dp array
    vector<int>dp(n+1,0);
    // Step 2 : Observe base case of top down
    dp[1] = k;
    dp[2] = k + k*(k-1);
    // Step 3 : Reverse the flow of top down
    for(int i = 3;i<=n;i++){
        dp[i] = (dp[i-2] + dp[i-1])*(k-1);
    }
    return dp[n];
}
// Space optimization 
int solveSpaceOpt(int n,int k){
    int prev2 = k;
    int prev1 = k + k*(k-1);
    for(int i = 3;i<=n;i++){
        int curr = (prev2 + prev1) * (k-1);
        // Shift logic (Can forget)
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
int main(){
    int n = 4;
    int k = 3;
    // Recursive code

    // int ans = solveRec(n,k);
    
    // Top down approach
    // Step 1 : Create dp array
    // vector<int>dp(n+1,-1);
    // int ans = solveTopDown(n,k,dp);

    // Bottom up approach
    // int ans = solveTab(n,k);

    // Space optimization
    int ans = solveSpaceOpt(n,k);
    cout<<"Colors required are "<<ans<<endl;
    return 0;
}