// Homework - 8 Fancy_Pattern1
#include<iostream>
using namespace std;
int main(){
    int n = 5;
    for(int i = 0; i<n;i++){
        // First print the stars
        int stars = n + 3 - i;
        for(;stars>0;stars--){
            cout<<"*";
        }
        // Print the number and star
        for(int j = 0;j<2*i+1;j++){
            if(j%2==0){
                cout<<i+1;
            }
            else{
                cout<<"*";
            }
        }
        // Print stars second time
        stars = n + 3 - i;
        for(;stars>0;stars--){
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}