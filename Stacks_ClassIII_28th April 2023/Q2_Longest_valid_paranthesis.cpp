// https://leetcode.com/problems/longest-valid-parentheses/

class Solution {
public:
    int longestValidParentheses(string s) {
        // Creation of stack
        stack<int>st;
        // Push -1 at the starting
        st.push(-1);
        int maxLen = 0;
        // Traversing the string
        for(int i = 0;i<s.length();i++){
            char ch = s[i];
            // Opening bracket encounterd -> Simply insert in the stack
            if(ch == '('){
                st.push(i);
            }
            else{ // Closing bracket
                // Simply pop
                st.pop();
                // Empty stack??
                if(st.empty()){
                    st.push(i);
                }
                else{ // Not empty simply calculate the length
                    int len = i - st.top();
                    maxLen = max(len,maxLen);
                }
            }
        }
        return maxLen;
    }
};