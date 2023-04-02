#include<iostream>
#include<set>
#include<vector>
using namespace std;
void findUnion(vector<int>&nums1,vector<int>&nums2){
    set<int>unique; // For unique elements only
    vector<int>ans; // Copy set elements to vector
    for(int i = 0;i<nums1.size();i++){ // Insert all elements of nums1 vector
        unique.insert(nums1[i]);
    }
    for(int j = 0;j<nums2.size();j++){ // Insert all elements of nums2 vector
        unique.insert(nums2[j]);
    }
    for(auto& it:unique){ // copy set elements to vector
        ans.push_back(it);
    }
    for(auto i:ans){ // Print the union vector
        cout<<i<<" ";
    }
}
int main(){
    vector<int>nums1{85,25,1,32,54,6};
    vector<int>nums2{85,2};
    findUnion(nums1,nums2);
    return 0;
}