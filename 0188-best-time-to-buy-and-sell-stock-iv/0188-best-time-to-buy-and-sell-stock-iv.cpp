class Solution{
private:
    int help(int idx, int tranNo, int k, vector<int> &prices, vector<vector<int>> &dp){
        if(idx == prices.size() || tranNo == 2 * k) return 0;

        if(dp[idx][tranNo] != -1) return dp[idx][tranNo];

        // Buy
        if(tranNo % 2 == 0){
            return dp[idx][tranNo] = max(-prices[idx] + help(idx+1, tranNo+1, k, prices, dp), help(idx+1, tranNo, k, prices, dp));
        }
        // Sell
        return dp[idx][tranNo] = max(+prices[idx] + help(idx+1, tranNo+1, k, prices, dp), help(idx+1, tranNo, k, prices, dp));
    }
public:
    int maxProfit(int k, vector<int>& prices){
        vector<vector<int>> dp(prices.size(), vector<int>(2 * k, -1));

        return help(0, 0, k, prices, dp);
        
    }
};



// class Solution {
// public:
//     int maxProfit(int k, vector<int>& prices) {
//         int n = prices.size();
//         auto dp = vector<vector<pair<int, int>>>(n, vector<pair<int, int>>(k+1, pair<int, int>({0, 0})));

//         for (int i = 0; i <= k; ++i) {
//             dp[n-1][i] = {0, prices[n-1]};
//         }
//         int maxTillNow = prices[n-1];
//         for (int i = n-2; i >= 0; --i) {
//             maxTillNow = max(maxTillNow, prices[i]);
//             dp[i][0] = {0, maxTillNow};
//         }


//         int res = 0;
//         for (int i = n-2; i >= 0; --i) {
//             for (int j = 1; j <= k; ++j) {
//                 int ans = 0;
//                 ans = max(dp[i+1][j].first, -prices[i] + dp[i+1][j-1].second);
//                 dp[i][j].first = ans;

//                 ans = 0;
//                 ans = max(dp[i+1][j].second, prices[i] + dp[i+1][j].first);
//                 dp[i][j].second = ans;

//                 if (i == 0) {
//                     res = max(res, dp[i][j].first);
//                 }
//             }
//         }
//         return res;
//     }
// };