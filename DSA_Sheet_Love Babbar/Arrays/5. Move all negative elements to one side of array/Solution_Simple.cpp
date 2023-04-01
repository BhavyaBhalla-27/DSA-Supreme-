#include<iostream>
#include<vector>
using namespace std;
void segElements(vector<int>&arr){
    vector<int>temp; // Temperory array
    // Step - 1 Push all the positive elements in the temp array
    for(int i = 0;i<arr.size();i++){
        if(arr[i]>=0){
            temp.push_back(arr[i]);
        }
    }
    // Step - 2 Push all the negative elements in the temp array after we push positive elements
    for(int i = 0;i<arr.size();i++){
        if(arr[i] < 0){
            temp.push_back(arr[i]);
        }
    }
    // Step - 3 Copy values from temp array to the original array
    for(int i = 0;i<temp.size();i++){
        arr[i] = temp[i];
    }
}
int main(){
    vector<int>arr{1, -1, 3, 2, -7, -5, 11, 6 }; // Test case of GFG
    segElements(arr);
    for(auto i:arr)
        cout<<i<<" ";
    return 0;
}