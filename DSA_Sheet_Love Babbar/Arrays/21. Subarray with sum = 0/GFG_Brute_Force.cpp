// https://practice.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1

class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        // Iterate all the subarrays and find that whether we can get sum = 0 or not.
        for(int i = 0;i<n;i++){
            int sum = 0;
            for(int j = i;j<n;j++){
                sum = sum + arr[j];
                if(sum == 0){
                    return true; // Found and hence return true
                }
            }
        }
        return false; // Not found
    }
};