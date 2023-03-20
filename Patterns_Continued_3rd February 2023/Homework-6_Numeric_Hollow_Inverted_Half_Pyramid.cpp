// Homework - 6 Numeric hollow inverted half pyramid
#include<iostream>
using namespace std;
int main(){
    int n = 5;
    for(int i = 0;i < n;i++){
        for(int j = 0;j<n - i ;j++){
            // first row
            if(i==0){ // first row then all numbers are printed
                cout<<j+1<<" ";
            }
            // last row
            else if(i == n-1){ // last row only n will be printed
                cout<<n;
            }
            else{
                if(j==0){ // first column, number starts from row-number + 1
                    cout<<i+1<<" ";
                }
                else if(j==n-i-1){ // for last column n is printed always
                    cout<<n;
                }
                else{ // if not first and not last column, then space will be printed
                    cout<<"  ";
                }
            }
        }
        cout<<endl;
    }
    return 0;
}