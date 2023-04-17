#include <iostream>
#include <vector>
#include <set>
using namespace std;
void commonElements(vector<int> &A, vector<int> &B, vector<int> &C)
{
    int n1 = A.size();
    int n2 = B.size();
    int n3 = C.size();
    // 3 Pointer approach
    vector<int> ans; // To return the answer
    set<int> s;      // For unique elements
    int i = 0;
    int j = 0;
    int k = 0;
    // Traverse till any of the array finishes
    while (i < n1 && j < n2 && k < n3)
    {
        // Found common element
        if (A[i] == B[j] && B[j] == C[k])
        {
            s.insert(A[i]);
            i++;
            j++;
            k++;
        }
        // Sorted thats why we are incrementing the pointers
        else if (A[i] < B[j])
        {
            i++;
        }
        else if (B[j] < C[k])
        {
            j++;
        }
        else
        {
            k++;
        }
    }
    for(auto i:s){
        cout<<i<<" ";
    }
}
int main()
{
    vector<int> A{1, 5, 10, 20, 40, 80};
    vector<int> B{6, 7, 20, 80, 100};
    vector<int> C{3, 4, 15, 20, 30, 70, 80, 120};
    commonElements(A, B, C);
    return 0;
}