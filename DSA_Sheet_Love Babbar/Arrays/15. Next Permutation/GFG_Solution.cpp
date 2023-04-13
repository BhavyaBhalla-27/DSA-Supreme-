// https://practice.geeksforgeeks.org/problems/next-permutation5226/1

class Solution{
public:
    vector<int> nextPermutation(int n, vector<int> arr){
        // Step - 1 => Find the longest prefix match
        int index = -1;
        for(int i = n-2;i>=0;i--){
            if(arr[i]<arr[i+1]){
                index = i;
                break;
            }
        }
        // Handling the edge case
        if(index == -1){
            reverse(arr.begin(),arr.end());
            return arr;
        }
        // Step - 2 => Find the element just greater than number present at the breakpoint
        for(int i = n-1;i>=0;i--){
            if(arr[i] > arr[index]){
                swap(arr[i],arr[index]);
                break;
            }
        }
        // Step - 3 => Reverse the array just after breakpoint 
        reverse(arr.begin() + index + 1,arr.end());
        return arr;
    }
};