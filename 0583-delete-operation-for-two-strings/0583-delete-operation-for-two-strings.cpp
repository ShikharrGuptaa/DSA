class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1.empty()) return word2.size();
        if(word2.empty()) return word1.size();

        vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1, -1));

        return help(word1, word2, 0, 0, dp);
    }

    int help(string &word1, string &word2, int ptr1, int ptr2, vector<vector<int>> &dp){
        if(ptr1 == word1.size()){
            return word2.size() - ptr2;
        }
        if(ptr2 == word2.size()){
            return word1.size() - ptr1;
        }

        if(dp[ptr1][ptr2] != -1) return dp[ptr1][ptr2];

        if(word1[ptr1] == word2[ptr2]){
            return dp[ptr1][ptr2] = help(word1, word2, ptr1+1, ptr2+1, dp);
        }

        int Del1 = 1 + help(word1, word2, ptr1+1, ptr2, dp);
        int Del2 = 1 + help(word1, word2, ptr1, ptr2+1, dp);

        return dp[ptr1][ptr2] = min(Del1, Del2);
    }
};