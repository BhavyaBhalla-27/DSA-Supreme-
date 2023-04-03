#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void rotateClockwise(vector<int>&nums,int k){
    // Make sure k remains in the range of 0 to nums.size() - 1
    // This can be done via mod operation
    if(k > nums.size()){
        k = k%nums.size();
    }
    // reverse the array
    reverse(nums.begin(),nums.end());
    // reverse the left part of array
    reverse(nums.begin(),nums.begin() + k);
    // reverse the right part of array
    reverse(nums.begin()+ k,nums.end());
    // print the array
    for(auto i:nums){
        cout<<i<<" ";
    }
}
int main(){
    vector<int>nums{1,2,3,4,5,6,7};
    int k = 3;
    rotateClockwise(nums,k);
    return 0;
}