// https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        // code here
        int pairs = 0;
        for(int i = 0;i<n;i++){
            for(int j = i + 1;j<n;j++){
                if(arr[i] + arr[j] == k){
                    pairs++;
                }
            }
        }
        return pairs;
    }
};