#include<iostream>
#include<vector>
using namespace std;
void sort0s1sand2s(vector<int>&nums) {
        int zeroCount = 0;
        int oneCount = 0;
        int twoCount = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] == 0)
                zeroCount++; // Storing count of 0
            else if(nums[i] == 1)
                oneCount++; // Storing count of 1
            else if(nums[i] == 2){
                twoCount++; // Storing count of 2
            }
        }
        int i = 0;
        while(zeroCount--){
            nums[i++] = 0; // Adding 0s to the array
        }
        while(oneCount--){
            nums[i++] = 1; // Adding 1s to the array
        }
        while(twoCount--){
            nums[i++] = 2; // Adding 2s to the array
        }
    }
int main(){
    vector<int>arr{2,0,2,1,1,0};
    sort0s1sand2s(arr);
    for(int i = 0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}