// Homework - 1 Solid Square Pattern (Rows = Columns)
#include<iostream>
using namespace std;
int main(){
    int n = 4; // general 
    for(int i = 0;i < n;i++){ // 0 to n-1 (both inclusive)
        for(int j = 0;j < n;j++){ // same as rows 
            cout<<"* "; // printing star
        }
        cout<<endl; // after printing each row go to the next line
    }
    return 0;
}