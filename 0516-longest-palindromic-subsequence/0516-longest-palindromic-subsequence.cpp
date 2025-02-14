class Solution {
private:
    int LCS(string &s, string &revStr, int i, int j, vector<vector<int>> &dp){
        if(i >= s.size() || j >= revStr.size()) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == revStr[j]) return dp[i][j] = 1 + LCS(s, revStr, i+1, j+1, dp);
        return dp[i][j] = max(LCS(s, revStr, i+1, j, dp), LCS(s, revStr, i, j+1, dp));
    }
public:
    int longestPalindromeSubseq(string s) {
        string revStr = s;
        // Reversing the String
        reverse(revStr.begin(), revStr.end());

        vector<vector<int>> dp(s.size(), vector<int>(revStr.size(), -1));

        return LCS(s, revStr, 0, 0, dp);
    }
};