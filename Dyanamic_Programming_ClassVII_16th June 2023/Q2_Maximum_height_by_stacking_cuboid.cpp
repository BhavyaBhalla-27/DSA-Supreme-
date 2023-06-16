// https://leetcode.com/problems/maximum-height-by-stacking-cuboids/description/

class Solution {
public:
    bool check(vector<int>a,vector<int>b){
        if(b[0] <= a[0] && b[1] <= a[1] && b[2] <= a[2])
            return true;
        else
            return false;
    }
    int spaceOpt(vector<vector<int>>&nums){
        int n = nums.size();
        vector<int>currRow(n+1,0);
        vector<int>nextRow(n+1,0);
        // Step 2 : Observe base case of top down -> already handled in initialization
        // Step 3 : Reverse the flow of top down
        for(int curr = n - 1;curr>=0;curr--){
            for(int prev = curr-1;prev>=-1;prev--){
                // include
                int include = 0;
                // change will be in the condition after || in most cases
                if(prev == -1 || check(nums[curr],nums[prev])){
                    // height need to be added
                    include = nums[curr][2] + nextRow[curr+1];
                }
                // exclude
                int exclude = 0 + nextRow[prev+1];
                currRow[prev+1] = max(include,exclude);
            }
            // Shift
            nextRow = currRow;
        }
        return nextRow[0];
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        // Sort every array
        for(auto &a:cuboids){
            sort(a.begin(),a.end());
        }
        // Sort the 2D array
        sort(cuboids.begin(),cuboids.end());
        // Apply LIS logic
        int ans = spaceOpt(cuboids);
        return ans;
    }
};