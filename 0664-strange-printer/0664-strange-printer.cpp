class Solution {
public:
    int strangePrinter(string s) {
        vector<vector<int>> dp(s.length() + 1, vector<int>(s.length() + 1, -1));
        return helper(0, s.length() -1, s, dp);
    }

    int helper(int i, int j, const string &s, vector<vector<int>> &dp){
        // If i goes beyond j, return 0;
        if(i > j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        char first = s[i];
        int answer = 1 + helper(i+1, j, s, dp);

        for(int k = i+1; k <= j; k++){
            if(s[k] == first){
                int betterAnswer = helper(i, k-1, s, dp) + helper(k+1, j, s, dp);
                answer = min(answer, betterAnswer);
            }
        }
        return dp[i][j] = answer;
    }
};