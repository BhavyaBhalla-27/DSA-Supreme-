// https://practice.geeksforgeeks.org/problems/the-painters-partition-problem1535/1

class Solution
{
    
  public:
    bool isPossible(int arr[],int n,int k,long long solution){
        long long timeSum = 0;
        int painterCount = 1;
        for(int i = 0;i<n;i++){
            if(arr[i] > solution){
                return false;
            }
            if(arr[i] + timeSum > solution){
                painterCount++;
                timeSum = arr[i];
                if(painterCount > k){
                    return false;
                }
            }
            else{
                timeSum += arr[i];
            }
        }
        return true;
    }
    long long minTime(int arr[], int n, int k)
    {
        long long start = 0;
        long long end = 0;
        for(int i = 0;i<n;i++){
            end += arr[i];
        }
        long long ans = -1;
        while(start<=end){
            // Find mid
            long long mid = start + (end-start)/2;
            if(isPossible(arr,n,k,mid)){
                // Store answer
                ans = mid;
                // Explore minimum time
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        return ans;
    }
};