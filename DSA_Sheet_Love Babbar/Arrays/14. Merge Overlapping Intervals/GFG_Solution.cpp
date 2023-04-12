// https://practice.geeksforgeeks.org/problems/8a644e94faaa94968d8665ba9e0a80d1ae3e0a2d/1

class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
         vector<vector<int>>ans;
         if(intervals.size() == 0){
             return ans;
         }
         sort(intervals.begin(),intervals.end());
         vector<int>temp = intervals[0];
         
         for(auto it : intervals){
             // Merging case
             if(it[0] <= temp[1]){
                temp[1] = max(temp[1],it[1]);                 
             }
             // Not Merging case
             else{
                 ans.push_back(temp);
                 temp = it; // Considering unmerged pair now
             }
         }
         ans.push_back(temp);
         return ans;
    }
};