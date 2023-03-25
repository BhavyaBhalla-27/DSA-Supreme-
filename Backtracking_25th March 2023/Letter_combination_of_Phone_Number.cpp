#include<iostream>
#include<vector>
using namespace std;
void solve(vector<string>&ans,int index,string output,string digits,vector<string>&mapping){
    // Base Case
    if(digits.length() == 0) // Empty string
        return;
    if(index >= digits.length()){ // Index goes out of string 
        ans.push_back(output);
        return;
    }
    // Solve 1 case and then recursion handles
    int digit = digits[index] - '0';
    string value = mapping[digit];
    for(int i = 0;i<value.length();i++){
        char ch = value[i];
        output.push_back(ch);
        solve(ans,index+1,output,digits,mapping);
        // Backtracking
        output.pop_back();
    }
}
int main(){

    vector<string>ans;
    int index = 0;
    vector<string>mapping(10);
    string output = "";
    string digits = "23";
    mapping[2] = "abc";
    mapping[3] = "def";
    mapping[4] = "ghi";
    mapping[5] = "jkl";
    mapping[6] = "mno";
    mapping[7] = "pqrs";
    mapping[8] = "tuv";
    mapping[9] = "wxyz";
    solve(ans,index,output,digits,mapping);
    if(ans.size() == 0){
        cout<<"Empty string";
    }
    for(int i = 0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}