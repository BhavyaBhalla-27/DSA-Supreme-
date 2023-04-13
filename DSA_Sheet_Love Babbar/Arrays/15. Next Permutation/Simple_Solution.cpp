#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void nextPermutation(vector<int>& nums) {
        // Step - 1 => Find the longest common prefix
        int n = nums.size(); 
        int index = -1; // Initially index say is -1
        for(int i = n-2;i>=0;i--){
            if(nums[i] < nums[i+1]){
                index = i; // Updating index
                break; // Once the index is found, simply exit the loop
            }
        }
        // Handling the edge case
        if(index == -1){ // index does not change
            // Last permutaion and hence reverse and return
            reverse(nums.begin(),nums.end()); // Last permutation has next permutation = 1st permutation 
            return; // Simply return
        }
        // Step - 2 => Swap the number at break point with element just greater
        for(int i = n - 1;i>=0;i--){
            if(nums[i]>nums[index]){ // If element found just greater than the breakpoint element
                swap(nums[i],nums[index]); // Swap 
                break;
            }
        }
        // Step - 3 => Reverse the array after the breakpoint
        reverse(nums.begin() + index + 1,nums.end()); 
    }
int main(){
    vector<int>nums{2,1,5,4,3,0,0};
    nextPermutation(nums);
    for(auto i : nums){
        cout<<i<<" ";
    }
    return 0;
}