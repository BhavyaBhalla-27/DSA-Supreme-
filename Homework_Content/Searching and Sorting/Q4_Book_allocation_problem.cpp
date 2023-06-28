// https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1

class Solution 
{
    public:
    bool isPossible(int A[],int N,int M,int sol){
        int pageSum = 0;
        int studentCount = 1;
        for(int i = 0;i < N;i++){
            // Number of pages is itself greater than solution 
            if(A[i] > sol){
                return false;
            }
            if(pageSum + A[i] > sol){
                studentCount++;
                pageSum = A[i];
                if(studentCount>M){
                    return false;
                }
            }
            else{
                    pageSum = pageSum + A[i];
                }
        }
        return true;
    }
    int findPages(int A[], int N, int M) 
    {
        // Number of students > Number of Books
        if(M > N){
            return -1;
        }
        int start = 0;
        int end = accumulate(A,A+N,0);
        int ans = -1;
        while(start<=end){
            // Find mid
            int mid = start + (end-start)/2;
            if(isPossible(A,N,M,mid)){
                // Store answer
                ans = mid;
                // Explore minimum 
                end = mid - 1;
            }
            else{
                // Not possible
                start = mid + 1;
            }
        }
        return ans;
    }
};