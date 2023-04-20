// https://practice.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1

class Solution {
public:
    vector<int> factorial(int N){
        vector<int>ans;
        // Initially push 1 to the ans 
        ans.push_back(1);
        int carry = 0;
        // For factorial multiplication
        for(int i = 2;i<=N;i++){
            // For storing the answer
            for(int j = 0;j<ans.size();j++){
                // Step - 1 -> find multiplication
                int x = ans[j] * i + carry;
                // Step - 2 -> store in ans
                ans[j] = x % 10;
                // Step - 3 -> Update carry
                carry = x/10;
            }
            // Push carry if it is there
            while(carry){
                // If carry is big then store it digit wise 
                ans.push_back(carry%10);
                carry = carry/10;
            }
        }
        // Reverse the answer
        reverse(ans.begin(),ans.end());
        return ans;
    }
};