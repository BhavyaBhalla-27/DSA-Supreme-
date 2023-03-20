#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>&arr,int target){
    // Base Case
    if(target == 0)
        return 0; // 0 is achieved by 0 value only
    if(target < 0)
        return INT_MAX; // So that value of mini is not updated as this is invalid case
    // Solve 1 case
    int mini = INT_MAX;
    for(int i = 0;i<arr.size();i++){
        int ans = solve(arr,target - arr[i]);
        if(ans != INT_MAX) // As ans + 1 will be out of range 
            mini = min(mini,ans + 1);
    }
    return mini;
}
using namespace std;
int main(){
    vector<int>arr{1,2};
    int target = 5;
    int ans = solve(arr,target);
    cout<<"Answer is "<<ans<<endl;
    return 0;
}