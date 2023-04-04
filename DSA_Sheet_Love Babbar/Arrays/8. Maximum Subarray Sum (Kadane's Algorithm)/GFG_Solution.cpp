// https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1

class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        
        // Your code here
        long long sum = 0;
        long long maxi = arr[0];
        for(int i = 0;i<n;i++){
            // Step - 1
            sum = sum + arr[i];
            // Step - 2
            maxi = max(sum,maxi);
            // Step - 3
            if(sum<0){
                sum = 0;
            }
            
        }
        return maxi;
        
    }
};