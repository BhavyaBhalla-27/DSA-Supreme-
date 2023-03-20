#include<iostream>
using namespace std;
void solve(int **q){
    q = q + 1; // No change
}
void solve1(int **q){
    *q = *q + 1; // Address of p will be changed
} 
void solve2(int **q){
    **q = **q + 1; // Value of x will be changed
}
int main(){
    int x = 12;
    int *p = &x;
    int **q = &p;
    cout<<"Before"<<endl;
    cout<<x<<endl;
    cout<<p<<endl;
    cout<<q<<endl;
    solve(q); // Modify these functions to see the changes
    cout<<"After"<<endl;
    cout<<x<<endl;
    cout<<p<<endl;
    cout<<q<<endl;
    return 0;
}