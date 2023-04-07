// https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1


class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            int i = n - 1; // Starting from the last index of the 1st array
            int j = 0; // Starting from the first index of the 2nd array
            while(i>=0 && j<m){ // Traverse until any of the loop finishes
                if(arr1[i] > arr2[j]){
                    // swap them because lower number elements will be in the 1st array and higher 
                    // number elements will be in 2nd array
                    swap(arr1[i],arr2[j]);
                    i--; // i is starting from the last index
                    j++; // j is starting from the 0th index
                }
                else{
                    // As the arrays are sorted if arr1[i] is not greater than the arr2[j] , this means arr1[i-1]
                    // will also not be greater and so on till the 0th index and hence we take a early exit
                    // from the loop
                    break;
                }
            }
            // Now the arrays we have got wont be sorted, so just sort them
            sort(arr1,arr1+n);
            sort(arr2,arr2+m);
        } 
};