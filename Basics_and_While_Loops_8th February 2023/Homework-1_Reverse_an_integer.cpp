#include<iostream>
using namespace std;
int main(){
    int num = -124; 
    int temp = num;
    int ans = 0;
    num = abs(num);  // if integer is negative, then take absolute value so that it goes inside the while loop
    while(num>0){
        int digit = num%10; // Find last digit
        ans = ans*10 + digit; // Same formulae as creating a number using digits
        num = num/10; // Same as that of creating a number using digits
    }
    if(temp<0){ // To make it work for negative integers as well. If input integer was negative then reversed integer will also be negative
        ans = -ans;
    }
    cout<<"reversed number is "<<ans<<endl;
    return 0;
}