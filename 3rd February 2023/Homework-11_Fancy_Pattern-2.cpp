#include<iostream>
using namespace std;
int main(){
    int n = 4;
    int num = 1;
    // Pattern - 1
    for(int i = 0;i<n;i++){
        for(int j = 0;j<2*i+1;j++){
            if(j%2==0){
                cout<<num<<" ";
                num++;
            }
            else{
                cout<<"* ";
            }
        }
        cout<<endl;
    }  
    // Pattern - 2
    int k = 2*n-1;
    for(int i = 0;i<n;i++){
        int j = 0;
        for(;j<2*n-2*i-1;j++){
            if(j%2==0){
                cout<<k<<" ";
                k++;
            }
            else{
                cout<<"* ";
            }
        }
        k = k - j;
        cout<<endl;
    }
    return 0;
}