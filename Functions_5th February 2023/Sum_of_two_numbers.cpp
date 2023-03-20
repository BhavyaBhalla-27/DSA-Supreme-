#include<iostream>
using namespace std;
int sum(int a,int b){ // int is return type, sum is function name, a and b are input parameters
    return (a+b);
}
int main(){
    int ans = sum(5,3);  // 5+3 will be returned to ans variable
    cout<<"Sum is "<<ans; // 8 is printed
    return 0;
}