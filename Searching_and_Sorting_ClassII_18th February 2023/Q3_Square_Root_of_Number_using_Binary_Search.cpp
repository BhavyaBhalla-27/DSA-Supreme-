#include<iostream>
using namespace std;
int squareRoot(int n){
    int s = 0;
    int e = n;
    int mid = s + (e-s)/2;
    int ans = -1;
    int target = n;
    while(s<=e){
        if(mid*mid == target){ // if exact square root is found
            ans = mid;
        }
        if(mid*mid>target){ // search in the left part
            e = mid - 1;
        }
        else{
            ans = mid; // store the answer as it might be a possible answer
            s = mid + 1; // search in right part
        }
        mid = s + (e-s)/2;
    }
    return ans;
}
int main(){
    int n = 10;
    double ans = squareRoot(n);
    int precision = 2;
    double step = 0.1;
    cout<<ans<<endl;
    for(int i = 0;i<precision;i++){
        for(double j = ans;j*j<=n;j=j+step){
            ans = j;
        }
        step/=10;
    }
    cout<<ans<<endl;
    return 0;
}