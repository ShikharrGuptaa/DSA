class Solution {
    int help(int idx, int buy, vector<int> &prices, vector<vector<int>> &dp){
        if(idx >= prices.size()) return 0;

        if(dp[idx][buy] != -1) return dp[idx][buy];
        // If Can Buy
        if(buy){
            // 2 Choices, to Buy OR Skip
            return dp[idx][buy] = max(-prices[idx] + help(idx+1, 0, prices, dp), help(idx+1, 1, prices, dp));
        }
        else{
            return dp[idx][buy] = max(+prices[idx] + help(idx+2, 1, prices, dp), help(idx+1, 0, prices, dp));
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return help(0, 1, prices, dp);
    }
};