#include<iostream>
#include<vector>
using namespace std;
int maximumProfit(vector<int>&prices){
    // INT_MAX choosen as we have to find minimum
    int mini = INT_MAX;
    int profit = 0; // Initially taken as zero
    for(int i = 0;i<prices.size();i++){
        // Update mini ?
        // Buying stock here
        if(prices[i] < mini){
            mini = prices[i];
        }
        else{ // Maybe right time to sell the stock
            profit = max(profit,prices[i] - mini); // We need maximum profit
        }
    }
    return profit;
}
int main(){
    vector<int>prices{7,1,5,3,6,4};
    int maxiProfit = maximumProfit(prices);
    cout<<"Maximum Profit = "<<maxiProfit;
    return 0;
}