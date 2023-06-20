#include<iostream>
#include<vector>
using namespace std;
void wavePrint(vector<vector<int>>&v){
    // Find number of rows
    int m = v.size();
    // Find number of columns
    int n = v[0].size();
    for(int i = 0;i<n;i++){
        // even number of column -> Top to Bottom
        if((i&1)==0){
            for(int j = 0;j<m;j++){
                cout<<v[j][i]<<" ";
            }
        }
        // odd number of column -> Bottom to top
        else{
            for(int j = m-1;j>=0;j--){
                cout<<v[j][i]<<" ";
            }
        }
    }
}
int main(){
    vector<vector<int>>v = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    wavePrint(v);
    return 0;
}