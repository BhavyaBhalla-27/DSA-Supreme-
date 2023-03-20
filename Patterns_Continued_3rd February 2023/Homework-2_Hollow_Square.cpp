// Homework - 2 Hollow Square Pattern 
#include<iostream>
using namespace std;
int main(){
    int n = 4; // general 
    for(int i = 0;i < n;i++){ // 0 to n-1 (both inclusive)
        for(int j = 0;j < n;j++){ // same as rows 
            if(j==0 || j == n-1 || i == 0 || i == n-1)
                cout<<"* "; // printing star only when 1st row or last row or 1st column or last column
            else    
                cout<<"  ";
        }
        cout<<endl; // after printing each row go to the next line
    }
    return 0;
}