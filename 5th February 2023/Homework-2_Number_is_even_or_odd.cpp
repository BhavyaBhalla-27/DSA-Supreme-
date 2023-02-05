#include<iostream>
using namespace std;
bool oddEven(int num){
    if(num%2==0){
        return true;
    }
    else    
        return false;
}
int main(){
    int num = 3;
    if(oddEven(num))
        cout<<"Number is even ";
    else   
        cout<<"Number is odd ";
    return 0;
}