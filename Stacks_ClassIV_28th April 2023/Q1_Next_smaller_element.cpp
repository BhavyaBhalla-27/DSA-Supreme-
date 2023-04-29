#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main(){
    vector<int>v{2,1,4,3};
    stack<int>s;
    vector<int>ans(v.size());
    // Push -1 initially
    s.push(-1);
    // Traverse from right to left
    for(int i = v.size() - 1;i>=0;i--){
        // Processing the current element
        int curr = v[i];
        while(s.top() >= curr){
            s.pop();
        }
        // Top element will be the answer -> Smaller element found
        ans[i] = s.top();
        // Push that element
        s.push(curr);
    }
    // Print the answer
    for(int i = 0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}