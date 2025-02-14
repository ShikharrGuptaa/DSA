class Solution {
// Recursion
private:
    bool isPalindrome(string &s, int start, int end){
        // If single Element Left, it'll always true;
        if(start >= end) return true;

        // Check for inner elements
        return s[start] == s[end] && isPalindrome(s, start+1, end-1);
    }
public:
    string longestPalindrome(string s) {
        int n = s.size();
        // int maxLen = 0;
        // int start = 0;

        // ----------------------Recursive Solution----------------------
        // // Introducing two loops because, we need one start and one end 
        // for(int i = 0; i < n; ++i){
        //     for(int j = i; j < n; ++j){
        //         // To ensure always Longest gets checked
        //         if(isPalindrome(s, i, j) && (j - i + 1 > maxLen)){
        //             maxLen = j-i+1;
        //             start = i;
        //         }   
        //     }
        // }

        // ----------------------Iterative Solution----------------------
        // Created a dp table to fill it correctly
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        
        // Single Element'll always be a palindrome
        int maxLen = 1;
        int start = 0;

        // Filling DP Table

        // For Len = 1;
        for(int i = 0; i < n; ++i){
            dp[i][i] = true;
        }

        // For Len = 2
        for(int i = 0; i < n-1; ++i){
            if(s[i] == s[i+1]){
                dp[i][i+1] = true;
                maxLen = 2;
                start = i;
            }
        }

        // For Len Greater than 2;

        // Outer Loop to keep track of length
        for(int len = 3; len <= n; ++len){
            // Inner loop to keep track of Length pointers
            for(int strt = 0; strt <= n - len; ++strt){
                int end = len + strt - 1;

                if(s[strt] == s[end] && dp[strt+1][end-1]){
                    maxLen = len;
                    start = strt;
                    dp[strt][end] = true;
                }
            }
        }
        return s.substr(start, maxLen);
    }
};