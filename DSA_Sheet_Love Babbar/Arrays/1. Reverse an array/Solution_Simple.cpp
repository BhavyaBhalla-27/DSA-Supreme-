#include<iostream>
#include<vector>
using namespace std;
void reverseArray(vector<int>&a){
    int i = 0; // First Index
        int j = a.size() - 1; // Last Index
        while(i<=j){
            swap(a[i],a[j]); // Swap the valuse
            i++; // Increment the value of i
            j--; // Decrement the value of j.
        }
}
int main(){
    vector<int>a{1,2,3,4,5};
    reverseArray(a);
    for(int i = 0;i<a.size();i++)
        cout<<a[i]<<" ";
    return 0;
}