// https://practice.geeksforgeeks.org/problems/union-of-two-arrays3538/1

class Solution{
    public:
    //Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m)  {
        //code here
        set<int>unique;
        vector<int>ans;
        for(int i = 0;i<n;i++){
            unique.insert(a[i]);
        }
        for(int j = 0;j<m;j++){
            unique.insert(b[j]);
        }
        return unique.size();
    }
};