// https://practice.geeksforgeeks.org/problems/move-all-negative-elements-to-end1813/1

class Solution{
    public:
    void segregateElements(int arr[],int n)
    {
        vector<int>ans; // Creating a temporary array
        // First push all the positive elements in the ans array
        for(int i = 0;i<n;i++){
            if(arr[i] >= 0)
                ans.push_back(arr[i]);
        }
        // After pushing positive elements push the negative elements in the array
        for(int i = 0;i<n;i++){
            if(arr[i] < 0)
                ans.push_back(arr[i]);
        }
        // Now copy the values from ans array to original array.
        for(int i = 0;i<n;i++){
            arr[i] = ans[i];
        }
        
    }
};