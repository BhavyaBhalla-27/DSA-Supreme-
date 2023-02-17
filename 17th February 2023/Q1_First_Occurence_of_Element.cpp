#include<iostream>
#include<vector>
using namespace std;
int firstOccurence(vector<int>v,int target){
    int s = 0;
    int e = v.size() - 1;
    int mid = s + (e-s)/2;
    int ans = -1;
    while(s<=e){
        if(v[mid]==target){
            // Store answer
            ans = mid;
            // Search in left
            e = mid - 1;
        }
        else if(target<v[mid]){
            e = mid - 1; // search in left part
        }
        else{
            s = mid + 1;// search in right part
        }
        mid = s + (e-s)/2;
    }
    return ans;
}
int main(){
    vector<int>v{1,3,4,4,4,4,4,6,7,9};
    int index = firstOccurence(v,4);
    cout<<index<<endl;
    return 0;
}