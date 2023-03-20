#include<iostream>
using namespace std;
void printCounting(int n){
    for(int i = 1;i<=n;i++){
        cout<<i<<" ";
    }
}
int main(){
    int n = 5;
    printCounting(n);
    return 0;
}