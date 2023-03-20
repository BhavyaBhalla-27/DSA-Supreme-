#include<iostream>
using namespace std;
int main(){
    int n = 6;
    
    for(int i = 0;i<n;i++){
        char ch = 'A'; // we always have to start from alphabet A
        for(int j = 0;j<i+1;j++){
            cout<<ch; 
            ch = ch + 1; // we have to print A,B .. so typecasting will be done here
        }
        ch = ch-2; // To go to the previous of the last alphabet as we will be 2 characters ahead and hence  ch = ch - 2 has been done here. 
        if(i!=0){ // dont do reverse count for 1st row 
            for(;ch>='A';ch--){
            cout<<ch;
        }
        }
        
        cout<<endl;
    }
    return 0;
}