class Solution {
private:
    int help(string &s, string &t, int ptr1, int ptr2, vector<vector<int>> &dp){
        if(ptr2 == t.size()) return 1;
        if(ptr1 >= s.size()) return 0;

        if(dp[ptr1][ptr2] != -1) return dp[ptr1][ptr2];

        int include = 0;
        if(s[ptr1] == t[ptr2]){
            include = help(s, t, ptr1+1, ptr2+1, dp);
        }

        int exclude = help(s, t, ptr1+1, ptr2, dp);

        return dp[ptr1][ptr2] = include + exclude;
    }
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size()+1, vector<int> (t.size()+1, -1));

        return help(s, t, 0, 0, dp);
    }
};