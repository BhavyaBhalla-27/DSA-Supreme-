// In Line-8 it was int8_t so I corrected it to int (Corrected line-8)
// In the for loop on Line-9 i should begin from 1 and go to n. int i = 1; i<=n (i should be less than equal to n and not less than n) (Corrected line-9)
#include<iostream>
using namespace std;
int main(){
    int n; 
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;++i){
        sum+=i;
    }
    cout<<sum<<endl;
    return 0;
}