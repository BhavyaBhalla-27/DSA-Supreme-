#include<iostream>
using namespace std;
bool checkPrime(int num){
    int factor = 0;
    if(num<2){
        return false;
    }
    for(int i = 2;i<num;i++){
        if(num%i==0){
            factor++;
            break;
        }
    }
    if(factor==1){
        return false;
    }
    else{
        return true;
    }
}
int main(){
    int num = 71;
    if(checkPrime(num)){
        cout<<"Prime "<<endl;
    }
    else{
        cout<<"Not Prime"<<endl;
    }
    return 0;
}