#include<iostream>
using namespace std;
int gcd(int a,int b){
    // Base case
    if(a == 0)
        return b;
    if(b == 0)
        return a;
    // Run the loop until any one of the parameter gets zero 
    while(a > 0 && b > 0){
        if(a>b) 
            a = a - b;
        else    
            b = b - a;
    }
    if(a == 0)
        return b;
    else   
        return a;
}
int main(){
    int a = 72;
    int b = 24;
    int ans = gcd(a,b);
    cout<<"HCF = "<<ans<<endl;
    int ans1 = (a*b)/ans;
    cout<<"LCM = "<<ans1;
    return 0;
}