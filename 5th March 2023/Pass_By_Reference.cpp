#include<iostream>
using namespace std;
void solve(int &x){ // Pass by reference concept 
    x++;
}
void solve1(int x){ // Pass by value concept
    x++;
}
int main(){
    int a = 5;
    solve(a);
    solve1(a);
    cout<<a<<endl;
    return 0;
}