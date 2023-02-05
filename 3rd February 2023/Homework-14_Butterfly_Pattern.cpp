#include<iostream>
using namespace std;
int main(){
    int n = 5;
    for(int i = 0;i<n;i++){
        // Pattern - 1
        for(int j = 0 ;j<i+1;j++){
            cout<<"* ";
        }
        // Space - 1
        int space = 2*(n-i-1);
        for(;space>0;space--){
                cout<<"  ";
        }
        // Pattern - 2
        for(int j = 0 ;j<i+1;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
    for(int i = 0;i<n;i++){
        // Pattern - 3
        for(int j = 0;j<n-i;j++){
            cout<<"* ";
        }
        // Space - 2
        int space = 2*i;
        for(;space>0;space--){
            cout<<"  ";
        }
        // Pattern - 4
        for(int j = 0;j<n-i;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
    return 0;
}