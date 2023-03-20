#include<iostream>
using namespace std;
int solve(int n,int x,int y,int z){
    // Base Case
    if(n == 0) // Cant cut any segment
        return 0;
    if(n < 0)
        return INT_MIN;
    // 1 case solve
    int a = solve(n - x,x,y,z) + 1;// + 1 has Same logic as done in minimum coin change
    int b = solve(n - y,x,y,z) + 1;// + 1 has Same logic as done in minimum coin change
    int c = solve(n - z,x,y,z) + 1;// + 1 has Same logic as done in minimum coin change
    int ans = max(a,max(b,c));
    return ans;
}
int main(){
    int n = 7;
    int x = 5;
    int y = 2;
    int z = 2;

    // Solve function -> Return maximum number of segments
    int ans = solve(n,x,y,z);
    if(ans < 0) // Invalid answer
        ans = 0;
    cout<<"Answer is "<<ans;
    return 0;
}