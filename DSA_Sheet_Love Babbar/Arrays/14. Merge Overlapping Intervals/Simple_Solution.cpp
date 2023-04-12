#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> mergeIntervals(vector<vector<int>>&arr){
    // Creation of the ans vector
    vector<vector<int>>ans;
    // Base Case/ Edge case -> If no intervals present
    if(arr.size() == 0){
        return ans;
    }
    // Temp vector to be created
    vector<int>temp = arr[0];
    // Linear Traversal
    for(auto i : arr){
        // Merging case
        if(i[0] <= temp[1]){
            temp[1] = max(i[1],temp[1]); // Maximum of the ending numbers should come at the ending of merged intervals
        }
        // Not Merging case
        else{
            ans.push_back(temp); // If not merged then simply push that pair
            temp = i; // Considering next pair
        }
    }
    // Push anything left 
    ans.push_back(temp);
    return ans;
}
int main(){
    vector<vector<int>>arr{
        {1,3},{2,6},{8,10},{15,18}
    };
    vector<vector<int>>ans = mergeIntervals(arr);
    for(int i = 0;i<ans.size();i++){
        for(int j = 0;j<ans[0].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}