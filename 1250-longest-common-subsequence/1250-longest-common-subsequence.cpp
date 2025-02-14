class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
        return help(dp, text1, text2, 0, 0);
    }
    int help(vector<vector<int>> &dp, const string &text1, const string &text2, int i, int j){
        if(i >= text1.size() || j >= text2.size()) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(text1[i] == text2[j]) return dp[i][j] = 1 + help(dp, text1, text2, i+1, j+1);

        return dp[i][j] = max(help(dp, text1, text2, i+1, j), help(dp, text1, text2, i, j+1));
    }
};