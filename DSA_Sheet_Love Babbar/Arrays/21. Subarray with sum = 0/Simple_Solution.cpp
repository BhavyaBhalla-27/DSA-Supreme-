#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
bool subArray(vector<int>&arr){
    unordered_map<int,int>m;
    int sum = 0;
    int n = arr.size();
    // Finding the prefix sum and then we can apply 2 conditions 
    for(int i = 0;i<n;i++){
        // prefix sum
        sum = sum + arr[i];
        // 2 condition check
        if(sum == 0 || m[sum] == 1){
            return true;
        }
        // mark visited or update map basically
        else{
            m[sum] = 1;
        }
    }
    return false;
}
int main(){
    vector<int>arr{4,2,-3,1,6};
    if(subArray(arr)){
        cout<<"Subarray with sum = 0 exists";
    }
    else{
        cout<<"Subarray with sum = 0 does not exist";
    }
    return 0;
}