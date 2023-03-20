#include<iostream>
using namespace std;
void setIthBit(int n,int i){
    int ans = 1<<i; // First left shift 1 by items
    ans = ans | n; // Bitwise OR is used as if any of the bit is 1, output will be 1
    cout<<ans<<endl;
}
int main(){
    int n = 3;
    setIthBit(n,3);
}