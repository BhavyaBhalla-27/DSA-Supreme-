#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
void findIntersection(vector<int>&nums1,vector<int>&nums2){
    // Step - 1 => Sorting step
    sort(nums1.begin(),nums1.end());
    sort(nums2.begin(),nums2.end());
    vector<int>ans;
    set<int>unique;
    // Step - 2 => Play with pointers/indexes
    int i = 0;
    int j = 0;
    int n1 = nums1.size();
    int n2 = nums2.size();
    while(i<n1 && j<n2){
        if(nums1[i] > nums2[j]){
            j++;
        }
        else if(nums1[i] < nums2[j]){
            i++;
        }
        else{
            unique.insert(nums1[i]);
            i++;
            j++;
        }   
    }
    // Step - 3 => Copy set elements to ans vector
    for(auto& it:unique){
        ans.push_back(it);
    }
    for(auto i:ans){
        cout<<i<<" ";
    }
}
int main(){
    vector<int>nums1{1,2,2,1};
    vector<int>nums2{2,2};
    findIntersection(nums1,nums2);
    return 0;
}