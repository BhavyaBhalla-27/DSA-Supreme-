#include<iostream>
using namespace std;
void findMissing(int arr[],int n){
    // Method - 1 
    // for(int i = 0;i<n;i++){
    //     int index = abs(arr[i]);
    //     if(arr[index - 1] > 0){
    //         arr[index -1] *= -1;
    //     }
    // }
    // // All positive elements have some relation with missing element
    // for(int i = 0;i<n;i++){
    //     if(arr[i] > 0){
    //         cout<<i+1<<" ";
    //     } 
    // }

    // Method - 2
    int i = 0;
    while(i<n){
        int index = arr[i] - 1;
        if(arr[i] != arr[index]){
            swap(arr[i],arr[index]);
        }
        else{
            i++;
        }
    }
    // Now simply traverse and see the mismatched element
    for(int i = 0;i<n;i++){
        int index = i + 1;
        if(arr[i]!=index){
            cout<<index<<" ";
        }
    }
}
int main(){
    int n = 5;
    int arr[] = {5,3,5,3,5};
    findMissing(arr,n);
    return 0;
}