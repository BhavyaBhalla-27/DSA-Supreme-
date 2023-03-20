#include<iostream>
using namespace std;
int main(){
    float num = 'b'; // The ASCII value of b is 98 which should be stored as 98.0 but again the compiler will ignore the .0 and hence 98 will be the output.
    cout<<num<<endl;
    return 0;
}