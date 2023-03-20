#include<iostream>
using namespace std;
int main(){
    int n = 5;
    for(int i = 0;i<n;i++){
        // For pattern-1
        for(int j = 0;j<2*i+1;j++){
            if(i<=(n/2)){
                if(j<=i)
                    cout<<j+1;
                else
                    cout<<2*i-j+1;
            }
        }
        // For pattern - 2
        for(int j = 0;j<=2*(n-i-1);j++){
            if(i>(n/2)){
                if(j<=i)
                    cout<<j+1;
                else
                    cout<<2*i-j+1;
            }
        }
        cout<<endl;
    }
    return 0;
}