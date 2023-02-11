#include<iostream>
#include<cmath>
using namespace std;
int binToDecimal(int bin){
    int ans = 0;
    int i = 0;
    while(bin>0){
        int bit = bin&1; // used bitwise AND
        ans = ans + bit*pow(2,i);
        i++;
        bin = bin>>1;
    }
    return ans;
}
int main(){
    int bin = 1011;
    int decimal = binToDecimal(bin);
    cout<<"Decimal value of binary number "<<bin<<" is "<<decimal;
    return 0;
}