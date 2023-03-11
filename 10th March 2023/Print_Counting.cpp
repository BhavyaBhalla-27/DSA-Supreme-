// Head Recursion example
#include<iostream>
using namespace std;
void count(int n){
    // Base case
    if(n == 0)
        return;
    // Recursive relation
    count(n-1);
    // Processing
    cout<<n<<" ";
}
int main(){
    int n = 5;
    count(n);
    return 0;
}