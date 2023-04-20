// https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-two-arrays2408/1

class Solution{
    public:
    string calc_Sum(int *a,int n,int *b,int m){
        // Start from the one's place
        int i = n - 1; 
        int j = m - 1;
        string ans;
        // Initially carry is set to 0
        int carry = 0;
        // When both the arrays are of equal length
        while(i>=0 && j>=0){
            // 1st step -> find the sum
            int x = a[i] + b[j] + carry;
            // 2nd step -> find the digit
            int digit = x%10;
            // 3rd step -> push the digit to the ans
            ans.push_back(digit + '0');
            // 4th step -> find the carry
            carry = x/10;
            // 5th step -> Update i and j
            i--;
            j--;
        }
        // When a array is bigger 
        while(i>=0){
            // 1st step -> find the sum
            int x = a[i] + carry;
            // 2nd step -> find the digit
            int digit = x%10;
            // 3rd step -> push the digit to the ans
            ans.push_back(digit + '0');
            // 4th step -> find the carry
            carry = x/10;
            // 5th step -> Update i
            i--;
        }
        // When b array is bigger 
        while(j>=0){
            // 1st step -> find the sum
            int x = b[j] + carry;
            // 2nd step -> find the digit
            int digit = x%10;
            // 3rd step -> push the digit to the ans
            ans.push_back(digit + '0');
            // 4th step -> find the carry
            carry = x/10;
            // 5th step -> Update j
            j--;
        }
        // Handling the case if carry was left 
        if(carry){
            // Simply push into the ans
            ans.push_back(carry + '0');
        }
        // If left of the digits are basically zero, then we have to ignore in case of string
        while(ans[ans.size() - 1] == '0'){
            ans.pop_back();
        }
        // Final answer is reverse 
        reverse(ans.begin(),ans.end());
        // Return the ans
        return ans;
    }
};