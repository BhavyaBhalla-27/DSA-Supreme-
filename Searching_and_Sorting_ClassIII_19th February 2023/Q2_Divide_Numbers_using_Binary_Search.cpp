#include<iostream>
using namespace std;
int solve(int dividend,int divisor){
    int s = 0;
    int e = abs(dividend); // always give positive number
    int mid = s + (e-s)/2;
    int ans = 1;
    while(s<=e){
        // Perfect Solution which no decimal point
        if(abs(mid*divisor) == abs(dividend)){
            ans = mid;
            break;
        }
        // Not perfect solutions
        if(abs(mid*divisor)>abs(dividend)){
            e = mid - 1;
        }
        else{
            ans = mid; // store answer
            s = mid + 1; // search in left
        }
        mid = s + (e-s)/2;
    }
    // handle the negative cases
    if((divisor<0 && dividend<0) || (divisor>0 && dividend>0))
        return ans;
    else{
        return -ans;
    }
    
}
int main(){
    int dividend = -21;
    int divisor = 7;
    int ans = solve(dividend,divisor);
    cout<<ans<<endl;
    return 0;
}