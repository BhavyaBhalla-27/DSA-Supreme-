#include<iostream>
using namespace std;
int main(){
    int arr[6] = {1,2,3,4,5,6};
    int start = 0;
    int end = 5;
    while(start<=end){
        if(start == end){ // for odd case
            cout<<arr[start]<<" "; // print once only
            break;
        }
        cout<<arr[start]<<" "; // normal case printing
        cout<<arr[end]<<" "; // normal case printing
        start++;// updating start pointer/variable
        end--; // updating end pointer/variable
    }
    return 0;
}