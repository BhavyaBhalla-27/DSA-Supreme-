// Leetcode - 22
#include<iostream>
#include<vector>
using namespace std;
void solve(vector<string>&ans,int n,int open,int close,string output){
    // Base Case
    if(open == 0 && close == 0){
        ans.push_back(output);
        return;
    }
    // Include the open bracket
    if(open>0){ // opening bracket avaialble or not
        output.push_back('(');
        solve(ans,n,open-1,close,output);
        // Backtracking
        output.pop_back();
    }
    // Include the closing bracket
    if(close>open){
        output.push_back(')');
        solve(ans,n,open,close-1,output);
        // Backtracking
        output.pop_back();
    }
}
int main(){
    vector<string>ans;
    int n = 2;
    int open = n;
    int close = n;
    string output = "";
    solve(ans,n,open,close,output);
    for(int i = 0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}