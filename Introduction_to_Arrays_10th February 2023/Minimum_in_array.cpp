#include<iostream>
#include<limits.h>
using namespace std;
int main(){
    int arr[5] = {3,1,2,5,4};
    int mini = INT_MAX; // best practice is to make mini = maximum possible integer value
    for(int i = 0;i<5;i++){ // linear search
        if(arr[i]<mini){ // comparing current number with the current minimum
            mini = arr[i]; // update mini if condition is fulfilled
        }
    }
    cout<<"Maximum element = "<<mini; // printing the minimum value
    return 0;
}