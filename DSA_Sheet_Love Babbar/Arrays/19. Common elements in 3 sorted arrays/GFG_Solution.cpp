class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            // 3 Pointer approach
            vector<int>ans; // To return the answer
            set<int>s; // For unique elements
            int i = 0;
            int j = 0;
            int k = 0;
            // Traverse till any of the array finishes
            while(i<n1 && j<n2 && k<n3){
                // Found common element
                if(A[i] == B[j] && B[j] == C[k]){
                    s.insert(A[i]);
                    i++;
                    j++;
                    k++;
                }
                // Sorted thats why we are incrementing the pointers
                else if(A[i] < B[j]){
                    i++;
                }
                else if(B[j] < C[k]){
                    j++;
                }
                else{
                    k++;
                }
            }
            // Copy set elements to the ans vector
            for(auto i:s){
                ans.push_back(i);
            }
            return ans;
        }

};