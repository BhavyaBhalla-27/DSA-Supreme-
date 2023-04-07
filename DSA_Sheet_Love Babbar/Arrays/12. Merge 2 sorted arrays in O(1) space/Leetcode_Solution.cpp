class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m + n - 1; // last index starting of 1st array
        int j = 0; // 0th index starting of 2nd array
        while(i>=0 && j < n){ // traverse until anyone of the array finishes or both arrays     
        // finishes
            // Do swapping until we have 0 there 
            if(nums1[i] == 0){
                swap(nums1[i--],nums2[j++]); // Decrement i and Increment j
            }
            else{
                break; // Now if we dont get 0, then this means some number has come and now if 
                // we get 0 again, this means it is the part of array
            }
        }
        sort(nums1.begin(),nums1.end()); // Sort the nums1 array to get the final answer
    }
};
