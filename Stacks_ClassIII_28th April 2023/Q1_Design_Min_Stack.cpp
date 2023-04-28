// https://leetcode.com/problems/min-stack/description/

class MinStack {
public:
    vector<pair<int,int>>st;
    MinStack() {
        
    }
    
    void push(int val) {
        // Empty vector
        // Both values same in this case
        if(st.empty()){
            pair<int,int>p = make_pair(val,val);
            st.push_back(p);
        }
        // Not empty case
        else{
            pair<int,int>p;
            p.first = val;
            // second element of pair will have minimum till now
            p.second = min(val,st.back().second);
            st.push_back(p);
        }
    }
    
    void pop() {
        // Simply pop 
        st.pop_back();
    }
    
    int top() {
        // Actual element -> First element of the last element of vector
        return st.back().first;
    }
    
    int getMin() {
        // Second element of the last element of vector
        return st.back().second;
    }
};