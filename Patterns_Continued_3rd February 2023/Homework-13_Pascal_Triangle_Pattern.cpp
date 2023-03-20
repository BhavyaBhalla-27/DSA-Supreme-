#include<iostream>
using namespace std;
int main(){
    int n = 7;
    for(int i = 1;i<=n;i++){
        int C = 1;
        for(int j = 1;j<=i;j++){
            cout<<C<<" ";
            C = C*(i-j)/j; // Formulae related to binomial
        }
        cout<<endl;
    }
    return 0;
}