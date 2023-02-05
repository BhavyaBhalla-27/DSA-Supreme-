// Homework - 3 Hollow inverted half pyramid
#include<iostream>
using namespace std;
int main(){
    int n = 6;
    for(int i = 0;i < n;i++){
        for(int j = 0;j<n - i - 1;j++){
            if(i==0 || j == 0 || j == n-i-2){
                cout<<"* ";
            }
            else{
                cout<<"  ";
            }
        }
        cout<<endl;
    }
    return 0;
}