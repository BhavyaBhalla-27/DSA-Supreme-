#include<iostream>
using namespace std;
void printDigits(int n){
    // Base Case
    if(n == 0)
        return;
    // Recursive Relation
    printDigits(n/10);
    // Processing
    int digit = n%10;
    cout<<digit<<" ";
}
int main(){
    int n = 0647;
    printDigits(n);
    return 0;  
}