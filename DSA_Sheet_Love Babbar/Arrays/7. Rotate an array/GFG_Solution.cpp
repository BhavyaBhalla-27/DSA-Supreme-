// https://practice.geeksforgeeks.org/problems/rotate-array-by-n-elements-1587115621/1

// Counter Clockwise direction rotation by d steps

class Solution{
    public:
    
    //Function to rotate an array by d elements in counter-clockwise direction. 
    void rotateArr(int arr[], int d, int n){
        // code here
        if(d > n){
            d = d%n;
        }
        reverse(arr,arr+n);
        reverse(arr,arr+n-d);
        reverse(arr+n-d,arr+n);
    }
};