#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>&gas,vector<int>&cost){
    // Shortage of petrol
    int deficit = 0;
    // How much petrol is left
    int balance = 0;
    // Starting index
    int start = 0;
    // Traverse the gas array
    for(int i = 0;i<gas.size();i++){
        balance = balance + gas[i] - cost[i];
        if(balance < 0){
            // This means deficit is there
            deficit = deficit + abs(balance);
            // Better approach - 1
            start = i + 1;
            // Start again and hence balance = 0
            balance = 0;
        }
    }
    // Answer found 
    if(balance >= deficit){
        return start;
    }
    // Answer not found
    return -1;
}
int main(){
    vector<int>gas {1,2,3,4,5};
    vector<int>cost {3,4,5,1,2};
    int ans = solve(gas,cost);
    cout<<"Starting index = "<<ans;
    return 0;
}