#include<iostream>
#include<vector>
using namespace std;
int main(){
    int a[] = {1,2,3,9,10,5};
    int sizea = 4;
    int b[] = {2,3,4,5,6,7,8};
    int sizeb = 7;
    bool flag = false;
    vector<int>output;
    // First put all the elements of a array in output array
    for(int i = 0;i<sizea;i++){
        output.push_back(a[i]);
    }
    // Now check array b and before inserting into output check whether element already inserted or not
    for(int i = 0;i<sizeb;i++){
        flag = false; // If flag becomes true, then make it false so that we check again
        for(int j = 0;j<output.size();j++){
            if(b[i]==output[j]){
                flag = true;
                break;
            }
        }
        if(!flag){
            output.push_back(b[i]);
        }
    }
    // Print output array
    for(int i = 0;i<output.size();i++){
        cout<<output[i]<<" ";
    }
    return 0;
}