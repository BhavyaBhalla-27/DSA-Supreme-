// Tail recursion example
#include<iostream>
using namespace std;
void count(int n){
    // Base case
    if(n == 0)
        return;
    // Processing
    cout<<n<<" ";
    // Recursive relation
    count(n-1);
}
int main(){
    int n = 5;
    count(n);
    return 0;
}