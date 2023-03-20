#include<iostream>
using namespace std;
int main(){
    int n = 40;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            // i == 0 so that the stars are printed for first row as there is no star missing there
            // j == 0 so that the stars in the first column are always printed
            // j == n-i-1 so that in the respective rows the stars will be printed in the last column
            if(i==0 || j==0 || j==n- 1 -i){
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