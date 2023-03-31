// https://leetcode.com/problems/sort-colors/submissions/924606716/
class Solution {
public:
    void sortColors(vector<int>& nums) {
       // Approach was simply count number of 0s,1s and 2s and simply place 0s first and then 1s and then 2s
       int zeroCount = 0;
       int oneCount = 0;
       int twoCount = 0;

       for(int i = 0;i<nums.size();i++){
           if(nums[i] == 0){
               zeroCount++;
           }
           else if(nums[i] == 1){
               oneCount++;
           }
           else{
               twoCount++;
           }
       } 
       int i = 0;
       while(zeroCount--){
           nums[i] = 0;
           i++;
       }
       while(oneCount--){
           nums[i] = 1;
           i++;
       }    
       while(twoCount--){
           nums[i] = 2;
           i++;
       }
    }
};