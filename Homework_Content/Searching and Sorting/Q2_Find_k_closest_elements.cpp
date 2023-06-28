// https://leetcode.com/problems/find-k-closest-elements/description/

class Solution {
public:
    int lowerBound(vector<int>&arr,int x){
        int start = 0;
        int end = arr.size() - 1;
        int ans = end; // Here I can do mistake
        while(start<=end){
            int mid = start + (end-start)/2;
            if(arr[mid]>=x){
                ans = mid;
                end = mid - 1;
            }
            else if(x > arr[mid]){
                start = mid+1;
            }
            else
                end = mid - 1;
        }
        return ans;
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // Method - 2
        // vector<int>ans;
        // int s = 0;
        // int e = arr.size() - 1;
        // while(e - s >= k){
        //     if(arr[e] - x < x - arr[s]){
        //         s++;
        //     }
        //     else{
        //         e--;
        //     }
        // }
        // // Push elements in answer
        // // while(s<=e){
        // //     ans.push_back(arr[s]);
        // //     s++;
        // // }
        // return vector<int>(arr.begin() + s,arr.begin() + e + 1);

        // Method - 3
        // Find lower bound
        int h = lowerBound(arr,x);
        int l = h - 1;
        while(k--){
            if(l < 0){
                h++;
            }
            else if(h>=arr.size()){
                l--;
            }
            else if(x - arr[l] > arr[h] - x){
                h++;
            } 
            else
                l--;
        }
        return vector<int>(arr.begin() + l + 1, arr.begin() + h);
    }
};