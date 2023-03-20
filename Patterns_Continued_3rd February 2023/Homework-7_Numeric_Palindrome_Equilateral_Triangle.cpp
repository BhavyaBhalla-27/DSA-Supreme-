// Homework - 7 Numeric palindrome equilaterial triangle
#include<iostream>
using namespace std;
int main(){
    int n = 5;
    for(int i = 0;i < n;i++){
        // Print the space
        int space = n - i - 1;
        for(;space>=0;space--){
            cout<<"  ";
        }
        // Print pattern - 1
        int num = 1;
        for(int j = 0; j < i+1 ;j++){
            cout<<num<<" "; // print start from 1 and goes on
            num++;
        }
        // Print pattern - 2 (reverse counting)
        num = num - 2; // one less than the previous number that's why decrement by 2 and not 1
        for(;num>=1;num--){
            cout<<num<<" ";
        }
        cout<<endl;
    }
    return 0;
}