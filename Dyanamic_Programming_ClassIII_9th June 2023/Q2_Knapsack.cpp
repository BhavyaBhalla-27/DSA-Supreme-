#include <iostream>
#include <vector>
using namespace std;
// index -> Last element index
int solveRec(int weight[], int value[], int index, int capacity)
{
    // Base case -> Only 1 item
    if (index == 0)
    {
        if (weight[0] <= capacity)
        {
            return value[0];
        }
        else
        {
            return 0;
        }
    }
    // include call
    int include = 0;
    if (weight[index] <= capacity)
    {
        // Here adding value[index] adding we can forget
        include = value[index] + solveRec(weight, value, index - 1, capacity - weight[index]);
    }
    // exclude call
    int exclude = 0 + solveRec(weight, value, index - 1, capacity);
    int ans = max(include, exclude);
    return ans;
}
int solveTopDown(int weight[], int value[], int index, int capacity, vector<vector<int>> &dp)
{
    // Base case -> Only 1 item
    if (index == 0)
    {
        if (weight[0] <= capacity)
        {
            return value[0];
        }
        else
        {
            return 0;
        }
    }
    // Step 3 : Answer already exists
    if (dp[index][capacity] != -1)
    {
        return dp[index][capacity];
    }
    // include call
    int include = 0;
    if (weight[index] <= capacity)
    {
        include = value[index] + solveTopDown(weight, value, index - 1, capacity - weight[index], dp);
    }
    // exclude call
    int exclude = 0 + solveTopDown(weight, value, index - 1, capacity, dp);
    // Step 2 : Store in dp array
    dp[index][capacity] = max(include, exclude);
    return dp[index][capacity];
}
// Bottom up approach
int solveTab(int weight[], int value[], int n, int capacity)
{
    // Step 1 : Create dp array
    vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));
    // Step 2 : Observe base case of top down
    // We have to run a loop for 0th index
    for (int w = 0; w <= capacity; w++)
    {
        if (weight[0] <= capacity)
        {
            dp[0][w] = value[0];
        }
        else
        {
            dp[0][w] = 0;
        }
    }
    // Step 3 : Reverse the flow of top-down
    // Replace n with index and capacity with wt
    for (int index = 1; index < n; index++)
    {
        for (int wt = weight[0]; wt <= capacity; wt++)
        {
            // include call
            int include = 0;
            if (weight[index] <= capacity)
            {
                include = value[index] + dp[index-1][wt-weight[index]];
            }
            // exclude call
            int exclude = 0 + dp[index-1][wt];
            dp[index][wt] = max(include, exclude);
        }
    }
    return dp[n-1][capacity];
}
// Space optimization - 1
int solveSpaceOpt1(int weight[], int value[], int n, int capacity){
    // Create 2 1D arrays
    vector<int>prev(capacity+1,0);
    vector<int>curr(capacity+1,0);
    for (int w = 0; w <= capacity; w++)
    {
        if (weight[0] <= capacity)
        {
            prev[w] = value[0];
        }
        else
        {
            prev[w] = 0;
        }
    }
    // Step 3 : Reverse the flow of top-down
    for (int index = 1; index < n; index++)
    {
        for (int wt = weight[0]; wt <= capacity; wt++)
        {
            // include call
            int include = 0;
            if (weight[index] <= capacity)
            {
                include = value[index] + prev[wt-weight[index]];
            }
            // exclude call
            int exclude = 0 + prev[wt];
            // Step 2 : Store in dp array
            curr[wt] = max(include, exclude);
        }
        // Shifting logic (we can forget this)
        prev = curr;
    }
    return prev[capacity];
}
// Space optimization - 2
int solveSpaceOpt2(int weight[], int value[], int n, int capacity){
    // Create 1D array
    vector<int>curr(capacity+1,0);
    for (int w = 0; w <= capacity; w++)
    {
        if (weight[0] <= capacity)
        {
            curr[w] = value[0];
        }
        else
        {
            curr[w] = 0;
        }
    }
    // Step 3 : Reverse the flow of top-down
    for (int index = 1; index < n; index++)
    {
        for (int wt = capacity; wt >=0; wt--)
        {
            // include call
            int include = 0;
            if (weight[index] <= capacity)
            {
                include = value[index] + curr[wt-weight[index]];
            }
            // exclude call
            int exclude = 0 + curr[wt];
            // Step 2 : Store in dp array
            curr[wt] = max(include, exclude);
        }
    }
    return curr[capacity];
}
int main()
{
    int weight[] = {4, 5, 1};
    int value[] = {1, 2, 3};
    int n = 3;
    int capacity = 4;
    // Recursive code
    // int ans = solveRec(weight,value,n-1,capacity);

    // Top down approach
    // Step 1 : Create dp array
    // Here we can stuck (Initialization part)
    // vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));
    // int ans = solveTopDown(weight, value, n - 1, capacity, dp);

    // Bottom up approach
    // int ans = solveTab(weight,value,n,capacity);

    // Space optimization - 1
    // int ans = solveSpaceOpt1(weight,value,n,capacity);

    // Space optimization - 2
    int ans = solveSpaceOpt2(weight,value,n,capacity);
    cout << "Maximum profit = " << ans;
    return 0;
}
