class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1));

        return help(coins.size()-1, amount, coins, dp);
    }

    int help(int idx, int amount, vector<int> &coins, vector<vector<int>> &dp){
        if(amount == 0) return 1;
        if(amount < 0 || idx < 0) return 0;

        if(dp[idx][amount] != -1) return dp[idx][amount];

        int exclude = help(idx-1, amount, coins, dp);

        int include = 0;
        if(coins[idx] <= amount){
            include = help(idx, amount - coins[idx], coins, dp);
        }

        return dp[idx][amount] = include + exclude;
    }
};