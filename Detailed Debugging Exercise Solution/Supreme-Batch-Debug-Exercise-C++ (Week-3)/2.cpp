// As the hint given to us is that it is an incomplete code, our direction of thinking should be that only.
// The candidate is returned directly without checking that whether the count of the candidate is greater than n/2 or not.
#include<iostream>
#include<vector>
using namespace std;
int majorityElement(vector<int>& nums) {
    int candidate,count = 0;
    // No n/2 is checked in the below condition
    for (int i = 0; i < nums.size(); i++) {
        if (count == 0) {
            candidate = nums[i];
        }
        if (nums[i] == candidate) {
            count++;
        } else {
            count--;
        }
    }
    // Additional code for checking the candidate is actually the candidate or not.
    int cnt = 0;
    for(int i = 0;i<nums.size();i++){
        if(candidate == nums[i]){
            cnt++;
        }
    }
    int ans = 0;
    (cnt > (nums.size()/2)) ? (ans = candidate) : (ans = -1);
    return ans;
}

int main() {
    vector<int> nums = {1,2,3,2,2,2,4};
    cout <<"The majority element is: "<< majorityElement(nums);
    return 0;
}