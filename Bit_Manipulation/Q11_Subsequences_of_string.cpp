#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void getSubsequences(string str){
    vector<string>ans;
    int n = str.length();
    for(int num = 0;num<(1<<n);num++){
        // Store subsequence in temp string
        string temp="";
        for(int i = 0;i<n;i++){
            char ch = str[i];
            if(num & (1<<i)){
                //include
                temp.push_back(ch);
            }
        }
        if(temp.length() >= 0){
            ans.push_back(temp);
        }
    }
    sort(ans.begin(),ans.end());
    for(auto i : ans){
        cout<<i<<" ";
    }
}
int main(){
    string str = "abc";
    getSubsequences(str);
    return 0;
}