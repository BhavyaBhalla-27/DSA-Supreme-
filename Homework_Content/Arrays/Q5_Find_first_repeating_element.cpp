// https://practice.geeksforgeeks.org/problems/first-repeating-element4018/1

class Solution {
  public:
    
    int firstRepeated(int arr[], int n) {
        
        // Method - 1
        
        // for(int i = 0;i<n;i++){
        //     for(int j = i+1;j<n;j++){
        //         if(arr[i] == arr[j]){
        //             return i+1;
        //         }
        //     }
        // }
        // return -1;
        
        // Method - 2
        // Store the count 
        unordered_map<int,int>hash;
        for(int i = 0;i<n;i++){
            hash[arr[i]]++;
        }
        // Traverse the array
        for(int i = 0;i<n;i++){
            if(hash[arr[i]]>=2){
                return i+1;
            }
        }
        return -1;
    }
};