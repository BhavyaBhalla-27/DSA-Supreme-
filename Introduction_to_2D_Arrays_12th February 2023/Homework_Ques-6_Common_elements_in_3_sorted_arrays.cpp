#include<iostream>
#include<vector>
#include<set>
using namespace std;
void commonElements(vector<int>&A,vector<int>&B,vector<int>&C){
    int n1 = A.size();
    int n2 = B.size();
    int n3 = C.size();
    set<int>st;
    int i = 0, j = 0, k = 0;
    while(i<n1 && j<n2 && k<n3){
    if(A[i] == B[j] && B[j] == C[k]){
        st.insert(A[i]); // So that unique elements come as output
        i++;
        j++;
        k++;
    }
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
    // Traverse the set and add elements from set to ans
    for(auto i:st){
        cout<<i<<" ";
    }
}
int main(){
    vector<int>A{1, 5, 10, 20, 40, 80};
    vector<int>B{6, 7, 20, 80, 100};
    vector<int>C{3, 4, 15, 20, 30, 70, 80, 120};
    commonElements(A,B,C);
    return 0;
}