#include<iostream>
using namespace std;
int main(){
    int val;
    cin>>val;
    switch(val){ // expression should be integer or character expression here
        case 1:cout<<"Bhavya"; break; // always use break after each case
        case 2: cout<<"Bhava1";break;
        case 3: cout<<"Bhavya2";break;
        default: cout<<"Class is over";break;
    }
    
    return 0;  
}