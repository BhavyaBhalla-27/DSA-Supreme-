// https://practice.geeksforgeeks.org/problems/sum-of-two-numbers-represented-as-arrays3110/1

class Solution{
public:	
	
	vector<int> findSum(vector<int> &a, vector<int> &b) {
	    vector<int>ans;
	    int carry = 0;
	    int i = a.size() - 1;
	    int j = b.size() - 1;
	    // Both have same digits
	    while(i>=0 && j>=0){
	        int x = a[i] + b[j] + carry;
	        int digit = x%10;
	        carry = x/10;
	        ans.push_back(digit);
	        i--;
	        j--;
	    }
	    // A has larger size
	    while(i>=0){
	       int x = a[i] + 0 + carry;
	       int digit = x % 10;
	       carry = x/10;
	       ans.push_back(digit);
	       i--;
	    }
	    // B has larger size
	    while(j>=0){
	        int x = 0 + b[j] + carry;
	        int digit = x % 10;
	        carry = x/10;
	        ans.push_back(digit);
	        j--;
	    }
	    // If carry is left
	    if(carry){
	        ans.push_back(carry);
	    }
	    // Reverse the answer
	    reverse(ans.begin(),ans.end());
	    return ans;
	}

};
