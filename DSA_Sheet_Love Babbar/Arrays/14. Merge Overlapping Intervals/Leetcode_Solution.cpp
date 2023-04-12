// https://leetcode.com/problems/merge-intervals/submissions/931947144/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans; // ans created
        // If there are no intervals and hence the ans also contain no intervals
        if(intervals.size() == 0){
            return ans;
        }
        sort(intervals.begin(),intervals.end());
        vector<int>tempInterval = intervals[0];
        for(auto it : intervals){
            if(it[0] <= tempInterval[1]){
                tempInterval[1] = max(it[1],tempInterval[1]);
            }
            else{
                ans.push_back(tempInterval);
                tempInterval = it;
            }
        }
        ans.push_back(tempInterval); // Last remaining interval to be pushed 
        return ans;
    }
};