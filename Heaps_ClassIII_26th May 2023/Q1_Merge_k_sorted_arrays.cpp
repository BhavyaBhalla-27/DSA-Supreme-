#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class info{
    public:
        int data;
        int row;
        int col;
        info(int val,int r,int c){
            data = val;
            row = r;
            col = c;
        }
};
class compare{
    public:
        bool operator()(info* a,info* b){
            return a->data > b->data;
        }
};
vector<int>mergeKSortedArrays(int arr[][4],int k,int n){
    // Creation of minHeap
    priority_queue<info*, vector<info*>, compare> minHeap;
    // Insert first elements of k arrays
    for(int i = 0;i<k;i++){
        info* temp = new info(arr[i][0],i,0);
        minHeap.push(temp);
    }
    // ans is stored in the vector 
    vector<int>ans;
    while(!minHeap.empty()){
        // Step - 1 : Find the top element 
        info* temp = minHeap.top();
        int topElement = temp->data;
        int topRow = temp->row;
        int topCol = temp->col;
        minHeap.pop();
        // Step - 2 : Top element remove and insert in ans vector
        ans.push_back(topElement);
        // Step - 3 : Is next index a valid index?
        if(topCol + 1 < n){
            info* newInfo = new info(arr[topRow][topCol + 1],topRow,topCol+1);
            minHeap.push(newInfo);
        }
    }
    return ans;
}
int main(){
    int arr[][4] = {{2,4,6,8},{1,3,5,7},{0,9,10,11}};
    int k = 3;
    int n = 4;
    vector<int>ans = mergeKSortedArrays(arr,k,n);
    for(auto i : ans){
        cout<<i<<" ";
    }
    return 0;
}