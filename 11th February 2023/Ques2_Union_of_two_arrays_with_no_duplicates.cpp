// Brute force approach is discussed -> We will discuss that if ans is returned in sorted array, there are duplicates as well in the array. In future we will discuss it.
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int arr[] = {1,3,5,7,9};
    int sizea = 5;
    int brr[] = {2,4,6,8};
    int sizeb = 4;
    vector<int>ans;
    // putting array elements of a in ans array
    for(int i=0;i<sizea;i++){
        ans.push_back(arr[i]);
    }
    // putting array elements of b in ans array
    for(int i=0;i<sizeb;i++){
        ans.push_back(brr[i]);
    }
    // printing ans array
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}