#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int getPairs(int arr[], int n, int k) {
        // Create an unordered map
        unordered_map<int,int>m;
        // Store the frequency of elements in the map
        for(int i = 0;i<n;i++){
            m[arr[i]]++;
        }
        int countPairs = 0;
        for(int i = 0;i<n;i++){
            if(m[k - arr[i]] != 0){ // Element is present 
                countPairs+=m[k-arr[i]];
            }
            if(k - arr[i] == arr[i]){ // so that (arr[i],arr[i]) pair is not considered
                countPairs--;
            }
        }
        int ans = countPairs/2; // (a,b) and (b,a) would have been counted and hence divided by 2
        return ans;
    }
int main(){
    int arr[] = {1,5,7,-1};
    int n = 4;
    int k = 6;
    int ans = getPairs(arr,n,k);
    cout<<"Number of pairs with a particular sum = "<<ans;
    return 0;
}