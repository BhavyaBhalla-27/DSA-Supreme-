#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int findDuplicate(vector<int>& nums) {
        // Simply sorting the array
        sort(nums.begin(),nums.end());
        int ans = nums[0]; // Random guess (We can take any array element here)
        // Just comparing adjacent elements
        for(int i = 1;i<nums.size();i++){ 
            if(nums[i-1] == nums[i]){
                ans = nums[i]; 
                break; // We got the answer then simply break as there can only be one duplicate in the array
            }
        }
        return ans; // Return the final answer
    }
int main(){
    vector<int>nums{1,4,4,2,4};
    int duplicate = findDuplicate(nums);
    cout<<"Duplicate element = "<<duplicate;
    return 0;
}