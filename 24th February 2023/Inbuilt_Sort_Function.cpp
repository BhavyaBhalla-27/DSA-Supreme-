#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int>arr{5,4,3,2,1};
    sort(arr.begin(),arr.end());
    for(int i = 0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}