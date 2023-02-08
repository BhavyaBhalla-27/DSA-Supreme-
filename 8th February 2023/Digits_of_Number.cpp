#include<iostream>
using namespace std;
int main(){
    int n = 623;
    while(n>0){ // condition
        int digit = n%10; // to find the last digit
        cout<<digit<<" ";
        n = n/10; // Reducing the number
    }
    return 0;
}