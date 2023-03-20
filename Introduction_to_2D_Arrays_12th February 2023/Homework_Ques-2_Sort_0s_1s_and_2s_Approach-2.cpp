#include<iostream>
#include<vector>
using namespace std;
void sort0s1sand2s(vector<int>&nums) {
    int l = 0;
    int m = 0;
    int h = nums.size() - 1;
    while(m<=h){
        if(nums[m] == 0){
            swap(nums[m],nums[l]);
            m++;
            l++;
        }
        else if(nums[m] == 1){
            m++;
        }
        else{
            swap(nums[m],nums[h]);
            h--;
        }
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