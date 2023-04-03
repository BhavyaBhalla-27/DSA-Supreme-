#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void rotateAntiClockwise(vector<int>&nums,int k){
    // Make sure k remains in the range of 0 to nums.size() - 1
    // This can be done via mod operation
    if(k > nums.size()){
        k = k%nums.size();
    }
    // reverse the array
    reverse(nums.begin(),nums.end());
    // reverse the left part of array
    reverse(nums.begin(),nums.begin() + nums.size() - k);
    // reverse the right part of array
    reverse(nums.begin()+nums.size()-k,nums.end());
    // print the array
    for(auto i:nums){
        cout<<i<<" ";
    }
}
int main(){
    vector<int>nums{2,4,6,8,10,12,14,16,18,20};
    int k = 3;
    rotateAntiClockwise(nums,k);
    return 0;
}