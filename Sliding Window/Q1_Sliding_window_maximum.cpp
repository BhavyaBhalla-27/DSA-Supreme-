// https://leetcode.com/problems/sliding-window-maximum/description/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>ans;
        // process first k sized window
        for(int i = 0;i<k;i++){
            // Remove smaller elements
            while(!dq.empty() && nums[dq.back()] < nums[i]){
                dq.pop_back();
            }
            // Insert element
            dq.push_back(i);
        }
        // Store answer for 1st window
        ans.push_back(nums[dq.front()]);
        // Process remaining windows
        for(int i = k;i<nums.size();i++){
            // removal
            if(!dq.empty() && i-k>=dq.front())
                dq.pop_front();
            // addition
            while(!dq.empty() && nums[dq.back()] < nums[i]){
                dq.pop_back();
            }
            // Insert element
            dq.push_back(i);
            // ans store
            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};