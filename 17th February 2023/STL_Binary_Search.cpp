#include<iostream>
#include<algorithm> // To use the binary_search() predefined function
#include<vector>
using namespace std;
int main(){
    int arr[] = {1,3,7,9,11,13,15,19};
    int size = 4;
    if(binary_search(arr,arr+size,3)){
        cout<<"Found"<<endl;
    }
    else{
        cout<<"Not found "<<endl;
    }
    vector<int>v{1,2,3,4,5,6};
    if(binary_search(v.begin(),v.end(),3)){ // Pre defined function 
        cout<<"Found"<<endl; 
    }
    else{
        cout<<"Not found "<<endl;
    }
    return 0;
}