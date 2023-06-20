// Order maintenance not required
#include<iostream>
#include<algorithm>
using namespace std;
void moveNegatives(int arr[],int n){
    // Method - 1
    // sort(arr,arr+n);

    // Method - 2
    int s = 0; // maintains negative numbers
    int e = n - 1; // maintains positive numbers
    while(s < e){
        // Case 1    
        if(arr[s] < 0)
            s++;
        // Case 2 
        else if (arr[e] > 0)
            e--;
        // Case 3
        else 
            swap(arr[s],arr[e]);
    }
}
int main(){
    int arr[] = {1,2,-3,4,-5,6};
    int n = 6;
    moveNegatives(arr,n);
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}