class Solution {
private: 
    bool help(string &s, string &p, int ptr1, int ptr2, vector<vector<int>> &dp){
        if(ptr1 >= s.size() && ptr2 >= p.size()) return true;
        if(ptr2 >= p.size()) return false;
        if(ptr1 >= s.size()){
            while(ptr2 < p.size() && p[ptr2] == '*') ptr2++;
            return ptr2 == p.size();
        }

        if(dp[ptr1][ptr2] != -1) return dp[ptr1][ptr2];

        if(s[ptr1] == p[ptr2] || p[ptr2] == '?'){
            return dp[ptr1][ptr2] = help(s, p, ptr1+1, ptr2+1, dp);
        }
        else if(p[ptr2] == '*'){
            return dp[ptr1][ptr2] = help(s, p, ptr1+1, ptr2, dp) || help(s, p, ptr1, ptr2+1, dp);
        }
        return dp[ptr1][ptr2] = false; 
    }
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size(), vector<int>(p.size(), -1));
        return help(s, p, 0, 0, dp);
    }
};