#include<iostream>
using namespace std;
int main(){
    double ch = 'a'; // Here the ASCII value of a will be 97 and it should have been stored as 97.0 but the compiler will again ignore the .0 and hence 97 will be the output
    cout<<ch<<endl;
    return 0;
}