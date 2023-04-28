// https://practice.geeksforgeeks.org/problems/e015cb4d3f354b035d9665e7c8a54a7aefb1901b/1

class Solution {
  public:
    int checkRedundancy(string s) {
        // Creation of stack
        stack<char> st;
        // Traverse the whole string
        for(int i = 0; i < s.length(); i++){
            // Opening bracket or operator -> Simply push
            if(s[i] == '(' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
                st.push(s[i]);
            }
            // Closing bracket or character
            else{
                // Considering only closing bracket
                if(s[i] == ')'){
                    // flag true means redundant 
                    bool flag = true;
                    // Checking the top whether it is opening or not
                    while(!st.empty() && st.top() != '('){
                        // If operator comes then not redundant 
                        if(st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/'){
                            flag = false;// false-> not redundant
                        }
                        // pop it
                        st.pop();
                    }
                    // Pop out opening bracket but check whether empty or not
                    if(!st.empty())
                        st.pop();
                    // Check the condition
                    if(flag == true){
                        return true;
                    }
                }
            }
        }
        // If true not returned then it is false
        return false;
    }
};