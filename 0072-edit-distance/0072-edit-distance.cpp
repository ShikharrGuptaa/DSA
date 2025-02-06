class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1.size() == 0) return word2.size();
        if(word2.size() == 0) return word1.size();
        vector<vector<int>> dp(word1.size(), vector<int>(word2.size(), -1));
        return help(dp, word1, word2, 0, 0);
    }
    // Ptr1 => Word1 && Ptr2 => Word2

    int help(vector<vector<int>> &dp, const string &word1, const string &word2, int ptr1, int ptr2){
        if(ptr1 >= word1.size()){
            return word2.size() - ptr2;
        }
        if(ptr2 >= word2.size()){
            return word1.size() - ptr1;
        }

        if(dp[ptr1][ptr2] != -1) return dp[ptr1][ptr2];
        // 3 Choices we have every time
        // 1 : Replace
        // 2 : Insert
        // 3 : Delete

        if(word1[ptr1] == word2[ptr2]){
            // Increased w-out any expense
            return dp[ptr1][ptr2] = help(dp, word1, word2, ptr1+1, ptr2+1);
        }
        int rep = 1 + help(dp, word1, word2, ptr1+1, ptr2+1);
        int ins = 1 + help(dp, word1, word2, ptr1, ptr2+1);
        int del = 1 + help(dp, word1, word2, ptr1+1, ptr2);

        return dp[ptr1][ptr2] = min({rep, ins, del});
    }
};