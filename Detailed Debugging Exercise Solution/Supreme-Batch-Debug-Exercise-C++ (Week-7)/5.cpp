// The base condition was edited from n < 0 to n == 0. This was observed as when I was dry running on test case 10,2
// Ans was coming out to be 10 + 10 + 10 = 30 but we need 20 and hence we observe that the call stack was having extra function call which was not needed and hence base case was modified to avoid this function.

#include<iostream>
using namespace std;
int multiplyNumbers(int m, int n) {
    if(n == 0)
        return 0;
    return m + multiplyNumbers(m,n-1);
}
int main(){
    int ans = multiplyNumbers(10,2);
    cout<<ans;
    return 0;
}