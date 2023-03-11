#include<iostream>
using namespace std;
int fib(int n){
    // Base case
    if(n == 1){
        // 1st term needed
        return 0;
    }
    if(n == 2){
        // 2nd term needed
        return 1;
    }
    // Recursive Relation
    int ans = fib(n-1) + fib(n-2);
    return ans;
}
int main(){
    int n = 5; // 5th term of the series we want
    int ans = fib(n);
    cout<<ans<<endl;
    return 0;
}