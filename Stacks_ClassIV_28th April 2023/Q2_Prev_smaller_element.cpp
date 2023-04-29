#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void prevSmallerElement(vector<int>&v){
    stack<int>s;
    s.push(-1);
    vector<int>ans(v.size());
    // Left to right traversal for prev smaller element
    for(int i = 0;i<v.size();i++){
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
    // print the answer vector
    for(int i = 0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}
int main(){
    vector<int>v{2,1,4,3};
    stack<int>s;
    prevSmallerElement(v);
    return 0;
}