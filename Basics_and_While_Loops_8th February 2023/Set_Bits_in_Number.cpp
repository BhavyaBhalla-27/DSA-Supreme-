#include<iostream>
using namespace std;
int main(){
    int n = 7;
    int count = 0; // Initially we take set bits as zero
    while(n!=0){ // Do until the number becomes 0
        if(n&1==1){ // To check for set bit
            count++; // If set bit is found, then increment count value
        }
        n = n>>1; // Do right shift 
    }
    cout<<count<<endl;
    return 0;
}