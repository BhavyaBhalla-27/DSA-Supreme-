// Better Approach -> 3 Pointer Approach
#include<iostream>
#include<vector>
using namespace std;
void sortColors(vector<int>&nums){
     int s = 0; // For replacing 0s
     int m = 0; // For replacing 1s
     int e = nums.size() - 1; // For replacing 2s

     // Loop 
     while(m<=e){
        // We got 0 (swap required)
        if(nums[m] == 0){
            swap(nums[s],nums[m]);
            s++;
            m++;
        }
        // We got 1 (no swap required)
        else if(nums[m] == 1){
            m++; // As 1 is at the correct position
        } 
        // We got 2 (swap required)
        else{
            swap(nums[m],nums[e]);
            e--;
        }
     }
}
int main(){
    vector<int>nums{2,0,1,2,0,0,1,1,0,2,1,1,0};
    sortColors(nums);
    for(auto i:nums){
        cout<<i<<" ";
    }
    return 0;
}