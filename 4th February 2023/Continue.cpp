#include<iostream>
using namespace std;
int main(){
    for(int i = 0;i<5;i++){
        if(i==2) // Here 0,1,3 and 4 will only be printed i.e. i = 2 iteration will be skipped
            continue;  // Skip a particular iteration
        cout<<i<<endl;
    }
    return 0;
}