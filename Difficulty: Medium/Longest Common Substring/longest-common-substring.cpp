//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
private:
    int LCS(string& s1, string& s2, int i, int j, vector<vector<int>>& dp, int& maxLen) {
        if (i >= s1.size() || j >= s2.size()) return 0;
        
        if (dp[i][j] != -1) return dp[i][j];

        if (s1[i] == s2[j]) {
            dp[i][j] = 1 + LCS(s1, s2, i+1, j+1, dp, maxLen);
            maxLen = max(maxLen, dp[i][j]); // Update longest substring length
            return dp[i][j];
        }

        return dp[i][j] = 0; // Reset on mismatch
    }

public:
    int longestCommonSubstr(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                LCS(s1, s2, i, j, dp, maxLen);
            }
        }
        
        return maxLen;
    }
};




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends