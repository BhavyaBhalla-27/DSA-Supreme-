#include<iostream>
#include<vector>
using namespace std;
int findRepeatingElement(vector<int>&arr){
    vector<int>countArray(1000000,0); 
    // Store the count of each element
    for(int i = 0;i<arr.size();i++){
        countArray[arr[i]]++;
    }
    // Traverse the input array and know whether count is greater than or equal to 2
    for(int i = 0;i<arr.size();i++){
        if(countArray[arr[i]] >= 2){
            int ans = arr[i];
            return ans;
        }
    }
    return -1; // If no repeating element exists
}
int main(){
    vector<int>arr{1,5,3,4,3,5,6};
    int ans = findRepeatingElement(arr);
    cout<<ans;
    return 0;
}