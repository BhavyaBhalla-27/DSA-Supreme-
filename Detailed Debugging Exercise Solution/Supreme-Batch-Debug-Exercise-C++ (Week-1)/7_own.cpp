#include<iostream>
using namespace std;
int main(){
    int n = 6;
    for(int i = 0;i<n;i++){
        // First print spaces
        int space = n-i-1;
        for(;space>=0;space--){
            cout<<"  ";
        }
        // Print number
        int num = i+1;
        for(int j = 0;j<=i;j++){
            cout<<num<<" ";
            num++;
        }
        // Again print number
        int ele = i;
        num = num-2;
        for(;ele>0;ele--){
            cout<<num<<" ";
            num--;
        }
        cout<<endl;
    }
    return 0;
}