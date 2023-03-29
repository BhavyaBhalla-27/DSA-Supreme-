#include<iostream>
#include<vector>
using namespace std;
void findMinandMax(vector<int>&arr){
    int mini = INT_MAX; // We follow this practice while finding the minimum element
    int maxi = INT_MIN; // We follow this practice while finding the maximum element
    for(int i = 0;i<arr.size();i++){
        if(arr[i] > maxi){ // Update maxi if element is greater than current maximum element
            maxi = arr[i]; // Updation step
        }
        if(arr[i] < mini){ // Update mini if element is lesser than current minimum element
            mini = arr[i]; // Updation step
        }
    }
    cout<<"Maximum element is "<<maxi<<endl;
    cout<<"Minimum element is "<<mini<<endl;
}
int main(){
    vector<int>arr{4,2,6,1,7,9,33,-22,45,100,-23,-65};
    findMinandMax(arr);
    return 0;
}