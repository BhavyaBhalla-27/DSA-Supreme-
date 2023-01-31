// Error - 1 We need to start the inner for loop from i + 1 because the first number in the row is row-number + 1. (Corrected Line - 12)
// Error - 2 In the if condition of inner forloop 
            // j == i+1 For printing the first column as there are no spaces
            // j == n-i-1 is changed to j == n because we have to print the number which is equal to n at the end only. (Corrected Line-13)
            // i==0 Because we have to print numbers and not spaces in the first row
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        for(int j=i+1;j<=n;j++){
            if(j==i+1 || j == n  || i == 0){
                cout<<j;
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
}