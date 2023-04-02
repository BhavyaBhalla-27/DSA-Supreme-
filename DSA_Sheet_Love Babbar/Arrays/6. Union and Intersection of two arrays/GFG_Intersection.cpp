// https://practice.geeksforgeeks.org/problems/intersection-of-two-arrays2404/1

class Solution {
  public:
    // Function to return the count of the number of elements in
    // the intersection of two arrays.
    int NumberofElementsInIntersection(int a[], int b[], int n, int m) {
        
        // Step - 1 => Sorting step
        sort(a,a+n);
        sort(b,b+m);
        set<int>unique;
        // Step - 2 => Play with pointers/indexes
        int i = 0;
        int j = 0;
        while(i<n && j<m){
            if(a[i] > b[j]){
                j++;
            }
            else if(a[i] < b[j]){
                i++;
            }
            else{
                unique.insert(a[i]);
                i++;
                j++;
            }   
        }
    return unique.size();
}
};