#include<iostream>
using namespace std;
int main(){
    // int i = 0 -> initialization
    // i<5 -> condition
    // i = i+1 -> updation
    for(int i = 0;i<5;i=i+1){
        cout<<i<<endl;
    }
     // int i = 0 -> initialization
    // i<3 -> condition
    // i = i+1 -> updation
    for(int i = 0;i<3;i=i+1){
        cout<<"Bhavya Bhalla"<<endl;
    }
    // int i = 0 -> initialization
    // i<=10 -> condition
    // i = i+1 -> updation
    for(int i = 0;i<=10;i=i+1){
        // This will print the table of 2
        cout<<2*i<<endl; 
    }
     // int i = 0 -> initialization
    // i<=10 -> condition
    // i = i+2 -> updation
    for(int i = 0;i<=5;i=i+2){
        cout<<i<<endl; 
    }
    // int i = 1 -> initialization
    // i<=20 -> condition
    // i = i*2 -> updation
    for(int i = 1;i<=20;i=i*2){
        cout<<i<<endl; 
    }
    // int i = 5 -> initialization
    // i>=0 && i<=10 -> condition
    // i = i+1 -> updation
    for(int i =5; (i>=0 && i<=10);i=i+1){
        cout<<i;
    }
}