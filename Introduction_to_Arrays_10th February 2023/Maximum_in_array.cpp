#include<iostream>
#include<limits.h>
using namespace std;
int main(){
    int arr[5] = {3,1,2,5,4};
    int maxi = INT_MIN; // best practice is to make maxi = minimum possible integer value
    for(int i = 0;i<5;i++){ // linear search
        if(arr[i]>maxi){ // comparing current number with the current maximum
            maxi = arr[i]; // update maxi if condition is fulfilled
        }
    }
    cout<<"Maximum element = "<<maxi; // printing the maximum value
    return 0;
}