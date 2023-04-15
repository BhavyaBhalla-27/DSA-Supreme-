// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

// The below solution is give TLE on 199th test case out of 211

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxiProfit = 0;
        // i-> buy
        // j-> sell
        for(int i = 0;i<prices.size();i++){
            for(int j = i + 1;j<prices.size();j++){
                int possibleMaxProfit = prices[j] - prices[i];
                maxiProfit = max(maxiProfit,possibleMaxProfit);
            }
        }
        return maxiProfit;
    }
};