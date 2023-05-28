#include<iostream>
#include<queue>
using namespace std;
int findKthSmallest(int arr[],int n,int k){
    // Create a max heap
    priority_queue<int>pq;
    // Insert starting k elements of the array
    for(int i = 0;i<k;i++){
        pq.push(arr[i]);
    }
    // For remaining elements, insert in heap if heap_top > element
    for(int i = k;i<n;i++){
        if(pq.top() > arr[i]){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}
int main(){
    int arr[] = {10,5,20,4,15};
    int n = 5;
    int k = 2;
    int ans = findKthSmallest(arr,n,k);
    cout<<"Ans = "<<ans;
    return 0;
}   