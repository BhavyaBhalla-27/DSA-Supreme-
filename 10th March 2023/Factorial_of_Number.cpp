#include<iostream>
using namespace std;
int factorial(int n){
    // Base case -> Always at top (Tells where to stop)
    if(n == 0 || n == 1)
        return 1;
    // Relation (Bigger problem to smaller problem and problem should be of same type)
    int ans = n * factorial(n-1);
    return ans;
}
int main(){
    int n = 5;
    int ans = factorial(n);
    cout<<ans;
    return 0;
}