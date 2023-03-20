#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
void findSum(vector<int> &a, vector<int> &b)
{
    vector<int> ans;
    int carry = 0; // Initially take carry = 0
    int i = a.size() - 1; // Start from the end digit that is one's digit of 1st number
    int j = b.size() - 1; // Start from end digit of 2nd number
    while (i >= 0 && j >= 0) // Traverse until we finish either of the number
    {
        int x = a[i] + b[j] + carry; // Formulae 
        int digit = x % 10; // Find one's digit
        ans.push_back(digit); // Push in the answer array
        carry = x / 10; // Update carry
        i--; // Move to next digit
        j--; // Move to next digit
    }
    while (i >= 0) // If first number has more digits than that of 2nd number
    {
        int x = a[i] + carry;
        int digit = x % 10;
        ans.push_back(digit);
        carry = x / 10;
        i--;
    }
    while (j >= 0) // If second number has more digits that that of 1st number
    {
        int x = b[j] + carry;
        int digit = x % 10;
        ans.push_back(digit);
        carry = x / 10;
        j--;
    }
    if (carry) // If there is carry left at the end, then push that also to the array
    {
        ans.push_back(carry);
    }
    reverse(ans.begin(), ans.end()); // Reverse the array as we have started from the end of the numbers and hence sum will also be reverse
    for(int i = 0;i<ans.size();i++){ 
        cout<<ans[i]<<" "; // Just print the ans array
    }
}
int main()
{
    vector<int>a{5,6,3};
    vector<int>b{8,4,2};
    findSum(a,b);
    return 0;
}