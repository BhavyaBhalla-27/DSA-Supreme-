#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool isPossible(vector<int>&cookRanks,int nP,int solution){
    int currP = 0; // initial parata count
    for(int i = 0;i<cookRanks.size();i++){
        int R = cookRanks[i];
        int j = 1;
        int timeTaken = 0;
        while(true){
            if(timeTaken + j*R <= solution){
                currP++; 
                timeTaken += j*R;
                j++;
            }
            else{
                break;
            }
        }
        if(currP >= nP){
            return true;
        }
    }
    return false;
}
int minTime(vector<int>&cookRanks,int nP){
    int start = 0;
    int highestRank = *max_element(cookRanks.begin(),cookRanks.end());
    int end = highestRank * (nP * (nP + 1))/2;
    int ans = -1;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(isPossible(cookRanks,nP,mid)){
            // Store possible answer
            ans = mid;
            // Exlpore for lesser time if possible
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    return ans;
}
int main(){
    int T; // number of test cases
    cin>>T;
    while(T--){
        int nP,nC;
        cin>>nP>>nC;
        vector<int>cookRanks;
        while(nC--){
            int R;
            cin>>R;
            cookRanks.push_back(R);
        }
        cout<<minTime(cookRanks,nP)<<endl;
    }

    return 0;
}   