#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>v){
    int s = 0;
    int e = v.size() - 1;
    int mid = s + (e-s)/2;
    while(s<=e){
        if(s==e){ // single element
            return s;
        }
        // mid is even index
        if(mid%2 == 0){
            if(v[mid] == v[mid + 1]){
                s = mid + 2; // search in right part and mid + 1 is explored thats why mid + 1 
            }
            else{
                e = mid; // as mid can be possible answer
            }
        }
        // mid is odd index
        else{
            if(v[mid] == v[mid-1]){
                s = mid + 1;// search in right part
            }
            else{
                e = mid - 1; // mid - 1 as mid can not be the answer
            }
        }
        mid = s + (e-s)/2;
    }
    return -1;
}
int main(){
    vector<int>v{1,1,2,2,3,3,4,4,3,600,600,4,4};
    int ans = solve(v);
    cout<<v[ans]<<endl;
    return 0;
}