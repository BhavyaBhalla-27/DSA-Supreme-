// https://leetcode.com/problems/sort-colors/description/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Method - 1 
        // sort(nums.begin(),nums.end());

        // Method - 2
        // int zeroCount = 0;
        // int oneCount = 0;
        // int twoCount = 0;
        // // Count number of 0s,1s and 2s
        // for(int i = 0;i<nums.size();i++){
        //     if(nums[i] == 0)
        //         zeroCount++;
        //     else if(nums[i] == 1)
        //         oneCount++;
        //     else if(nums[i] == 2)
        //         twoCount++;
        // }
        // // Spread in array
        // int i = 0;
        // while(zeroCount--){
        //     nums[i++] = 0;
        // }
        // while(oneCount--){
        //     nums[i++] = 1;
        // }
        // while(twoCount--){
        //     nums[i++] = 2;
        // }

        // Method - 3
        int s = 0; // for placing 0s
        int m = 0; // for placing 1s
        int e = nums.size() - 1; // for placing 2s
        while(m <= e){
            // Case 1 
            if(nums[m] == 0)
                swap(nums[s++],nums[m++]);
            // Case 2
            else if(nums[m] == 1)
                m++;
            // Case 3
            else if(nums[m] == 2)
                swap(nums[m],nums[e--]); 
        }
    }
};