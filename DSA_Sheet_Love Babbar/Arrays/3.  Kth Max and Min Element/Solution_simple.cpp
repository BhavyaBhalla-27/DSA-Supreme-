#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void findkthMinandMaxElement(vector<int>&arr,int k){
    sort(arr.begin(),arr.end());
    // Maximum Element
    int n = arr.size();
    int maxi = arr[n - k];
    cout<<k<<"rd maximum element is "<<maxi<<endl;
    // Minimum Element 
    int mini = arr[k - 1];
    cout<<k<<"rd minimum element is "<<mini;
}
int main(){
    vector<int>arr{7,10,4,3,20,15};
    int k = 3;
    findkthMinandMaxElement(arr,k);
    return 0;
}