// https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1

class Solution{   
public:
    
    int getPairsCount(int arr[], int n, int k) {
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
};