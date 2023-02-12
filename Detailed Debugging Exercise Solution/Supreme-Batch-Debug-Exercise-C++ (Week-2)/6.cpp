// In line-6, intialize the ans = 0 else it will take some garbage value and produce false result (Corrected Line - 6)
// In Line-9, we need to do ans += (b%10)*(1<<c++) --> (Corrected Line-9) as if we do just ans = (b%10)*(1<<c++) then only last bit would be considered and we would get the answer on the basis of last bit only
#include<iostream>
using namespace std;
int binaryToDecimal(int b){
    int ans = 0;
    int c=0;
    while(b){
        ans+=(b % 10) * (1 << c++);
        b/=10;
    }
    return ans;
}
int main(){
    cout<<binaryToDecimal(1010);
    return 0;
}