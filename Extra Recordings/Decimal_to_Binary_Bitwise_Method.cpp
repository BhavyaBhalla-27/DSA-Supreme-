#include<iostream>
#include<cmath>
using namespace std;
int decToBinMethod1(int n){
    // Bitwise method
    int binaryNumber = 0;
    int i = 0;
    while(n>0){
        int bit = n&1;
        // Now we need to make a number from bits (Number from digits questions is used)
        binaryNumber = bit*pow(10,i) + binaryNumber;
        n = n>>1;
        i++;
    }
    return binaryNumber;
}
int main(){
    
    int n;
    cin>>n;
    int binary = decToBinMethod1(n);
    cout<<"Binary number of "<<n<<" is "<<binary<<endl;
    return 0;
}