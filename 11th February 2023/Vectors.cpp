#include<iostream>
#include<vector> // vector header file to use vector in our program
using namespace std;
int main(){
    vector<int>arr;
    int ans = (sizeof(arr)/sizeof(int)); // compiler dependent
    cout<<ans<<endl;
    // checking default array size
    cout<<arr.size()<<endl; // size is how many elements are stored
    cout<<arr.capacity()<<endl; // capacity is total elements that can be inserted 
    // insertion
    arr.push_back(5); // inserting 5 
    arr.push_back(6); // inserting 6
    // printing vector
    for(int i = 0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    // Removes last element inserted
    arr.pop_back();
    // initialization
    vector<int>crr(10,1);
    for(int i = 0;i<crr.size();i++){
        cout<<crr[i]<<" ";
    }
    cout<<endl;
    // empty function
    cout<<crr.empty()<<endl;
    vector<int>drr;
    cout<<drr.empty()<<endl;
    return 0;
}