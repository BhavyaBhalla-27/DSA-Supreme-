// Instead of (N/2) - 1 write (N/2)
// N - i would be an invalid index when i = 0 and hence N - i - 1 was written
#include<iostream>
using namespace std;
string isPalindrome(string S)
{
	int N = S.length();
    for (int i = 0; i < (N/2); i++) {
		    if (S[i] != S[N-i-1]) {
            return "No";
        }
    }
    return "Yes";
}
int main(){
    if(isPalindrome("abcba") == "Yes"){
        cout<<"Palindrome";
    }
    else{
        cout<<"Not Palindrome";
    }
    return 0;
}