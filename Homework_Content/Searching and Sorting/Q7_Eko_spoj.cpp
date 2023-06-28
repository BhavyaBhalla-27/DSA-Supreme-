// https://www.spoj.com/problems/EKO/

    #include<iostream>
    #include<vector>
    #include<algorithm>
    using namespace std;
    bool isPossible(vector<long long int>&trees,long long int m,long long int solution){
        long long int woodCollected = 0;
        for(int i = 0;i<trees.size();i++){
            if(trees[i] > solution){
                woodCollected += trees[i] - solution;
            }
        }
        return woodCollected>=m;
    }
    long long int maxSawBladeHeight(vector<long long int>&trees,long long int m){
        long long int start = 0;
        long long int end = *max_element(trees.begin(),trees.end());
        long long int ans = -1;
        while(start<=end){
            long long int mid = start + (end-start)/2;
            if(isPossible(trees,m,mid)){
                // Store answer
                ans = mid;
                // Go for higher height for less wood
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
        return ans;
    }
    int main(){
        long long int n,m;
        cin>>n>>m;
        vector<long long int>trees;
        while(n--){
            long long int height;
            cin>>height;
            trees.push_back(height);
        }
        cout<<maxSawBladeHeight(trees,m)<<endl;
        return 0;
    }