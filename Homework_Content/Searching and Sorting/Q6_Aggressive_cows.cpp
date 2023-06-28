// https://practice.geeksforgeeks.org/problems/aggressive-cows/1

class Solution {
public:
    bool isPossible(vector<int>&stalls,int n,int k,int solution){
        int cowCount = 1;
        int pos = stalls[0];
        for(int i = 1;i<n;i++){
            if(stalls[i] - pos >= solution){
                cowCount++;
                pos = stalls[i];
            }
            if(cowCount == k)
                return true;
        }
        return false;
    }
    int solve(int n, int k, vector<int> &stalls) {
        // Sort the stalls as we need to apply binary search algorithm
        sort(stalls.begin(),stalls.end());
        // Defining search space
        int start = 0;
        int end = stalls[n-1] - stalls[0];
        int ans = -1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(isPossible(stalls,n,k,mid)){
                // Store it
                ans = mid;
                // Go ahead to get maximum possible solution
                start = mid + 1;
            }
            else{
                // Go behind 
                end = mid - 1;
            }
        }
        return ans;
    }
};