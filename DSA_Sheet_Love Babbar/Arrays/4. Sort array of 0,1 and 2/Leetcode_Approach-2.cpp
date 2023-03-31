// https://leetcode.com/problems/sort-colors/submissions/924609763/
class Solution {
public:
    void sortColors(vector<int>& nums) {
       // 3 Pointer Approach
       int s = 0;
       int m = 0;
       int e = nums.size() - 1;
       while(m<=e){
           // If 0 then place at start (swap required)
           if(nums[m] == 0){ 
               swap(nums[s],nums[m]);
               s++;
               m++;
           }
          // If 1 then place at mid (no swap required)
          else if(nums[m] == 1){
              m++;
          }
           // If 2 then place at end (swap required)
           else{
               swap(nums[m],nums[e]);
               
               e--;
           }
       }
    }
};