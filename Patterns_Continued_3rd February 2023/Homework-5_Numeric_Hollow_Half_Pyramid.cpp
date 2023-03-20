// Pattern - 5 Numeric hollow half pyramid
#include<iostream>
using namespace std;
int main(){
    int n = 6;
    for(int i = 0; i < n ; i++){
        for(int j = 0;j<i+1;j++){
            if(i == 0){ // for first row we just have to print 1
                cout<<1;
            }
            // last row
            else if(i==n-1){ // for last row we have to print numbers from 1 to n
                cout<<j+1<<" "; 
            }
            else{ // if not first and not last row then
                if(j == 0){ // first column then print 1 as 1 is always the first number we print
                    cout<<1<<" ";
                }
                else if(j==i){ // last column then print one more than i (observation)
                    cout<<i+1<<" ";
                }
                else{
                    cout<<"  "; // if in between columns then just print spaces
                }
            }
        }
         cout<<endl;
    }
       
    
    return 0;
}