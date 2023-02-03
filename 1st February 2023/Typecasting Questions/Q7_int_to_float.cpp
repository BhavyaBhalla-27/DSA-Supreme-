#include<iostream>
using namespace std;
int main(){
    float num = 9; // 9.0 should be the correct answer but the compiler will ignore .0 and hence 9 will be the output 
    cout<<num<<endl;
    return 0;
}