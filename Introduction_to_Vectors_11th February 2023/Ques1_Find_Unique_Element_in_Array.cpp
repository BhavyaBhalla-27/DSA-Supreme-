#include<iostream>
#include<vector>
using namespace std;
int findUniqueElement(vector<int> arr){
    int ans = 0; // initialized with 0 as xor with 0 will give the number itself (a^0 = a)
    for(int i = 0;i<arr.size();i++){
        ans = ans ^ arr[i]; // xor all the elements and cancelling repeated elements and at the end we get unique element
    }
    return ans;
}
int main(){
    int n;
    cout<<"Enter the size of array "<<endl;
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter the elements "<<endl;
    for(int i = 0;i<arr.size();i++){
        cin>>arr[i];
    }
    int uniqueElement = findUniqueElement(arr);
    cout<<"Unique element in the array is "<<uniqueElement<<endl;
    return 0;
}