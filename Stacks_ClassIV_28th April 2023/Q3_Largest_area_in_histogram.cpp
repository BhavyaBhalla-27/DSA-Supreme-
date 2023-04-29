#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int>prevSmallerElement(vector<int>&v){
    stack<int>s;
    s.push(-1);
    vector<int>ans(v.size());
    // Left to right traversal for next smaller element
    for(int i = 0;i<v.size();i++){
        // Processing the current element
        int curr = v[i];
        while(s.top() != -1 && v[s.top()] >= curr){
            s.pop();
        }
        // Top element will be the answer -> Smaller element found
        ans[i] = s.top();
        // Push that index
        s.push(i);
    }
    return ans;
}
vector<int>nextSmallerElement(vector<int>&v){
    stack<int>s;
    s.push(-1);
    vector<int>ans(v.size());
    // Right to left traversal for prev smaller element
    for(int i = v.size() -1 ;i>=0;i--){
        // Processing the current element
        int curr = v[i];
        while(s.top() != -1 && v[s.top()] >= curr){
            s.pop();
        }
        // Top element will be the answer -> Smaller element found
        ans[i] = s.top();
        // Push that index
        s.push(i);
    }

    return ans;
}
int largestRectangleArea(vector<int>& heights) {
    // Previous smaller element array
    vector<int>prev = prevSmallerElement(heights);
    // Next smaller element array
    vector<int>next = nextSmallerElement(heights);
    // Find the max area
    int size = heights.size();
    int maxArea = INT_MIN;
    for(int i = 0;i<heights.size();i++){
        int length = heights[i];
        if(next[i] == -1){
            next[i] = size;
        }
        int width = next[i] - prev[i] - 1;
        int area = length*width;
        maxArea = max(maxArea,area);
    }
    return maxArea;
}
int main(){
    vector<int>heights{2,1,5,6,2,3};
    int ans = largestRectangleArea(heights);
    cout<<"Maximum area = "<<ans;
    return 0;
}