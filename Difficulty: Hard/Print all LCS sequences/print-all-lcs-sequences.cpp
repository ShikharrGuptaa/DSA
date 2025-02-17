//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
private:
    void LCS(string &s1, string &s2, vector<vector<int>> &dp){
        int m = s1.size();
        int n = s2.size();
        
        for(int i = 1; i <= m; ++i){
            for(int j = 1; j <= n; ++j){
                // Due to 1-Based Indexing
                if(s1[i-1] == s2[j-1]){
                    // Element matched, check for previous element
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    // Element not matched, check by increasing either of two and saving maximum of those
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
    }
    
    void allLCS(int i, int j, string temp, string &s1, string &s2, set<string> &ansSet, vector<vector<int>> &dp, unordered_map<string, bool> &mapping){
        // Traversed all string
        if(i == 0 || j == 0){
            // As we went right to left, ans was stored in reverse direction
            reverse(temp.begin(), temp.end());
            ansSet.insert(temp);
            return;
        }
        
        // Making a key to store that we visited {i, j, forming this temp string}
        string key = to_string(i) + "," + to_string(j) + "," + temp;
        
        // If Current State is found, no need to go through it again
        if(mapping.find(key) != mapping.end()) return;
        
        mapping[key] = true; // Marking it visited now
        
        if(s1[i-1] == s2[j-1]){
            allLCS(i-1, j-1, temp+=s1[i-1], s1, s2, ansSet, dp, mapping);
            // temp.pop_back();
        }
        else{
            if(dp[i][j] == dp[i-1][j]) allLCS(i-1, j, temp, s1, s2, ansSet, dp, mapping);
            if(dp[i][j] == dp[i][j-1]) allLCS(i, j-1, temp, s1, s2, ansSet, dp, mapping);
        }
    }
    
  public:
    vector<string> all_longest_common_subsequences(string s, string t) {
        // Code here
        int m = s.size(), n = t.size();
        // Forming a DP Table to store LCS
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        // Performing LCS
        LCS(s, t, dp);
        
        // Set for storing LCS
        set<string> ansSet;
        string temp = ""; // String to store backtracked results;
        
        unordered_map<string, bool> mapping; // Map to store visited elements
        
        allLCS(m, n, temp, s, t, ansSet, dp, mapping);
        
        vector<string> ans(ansSet.begin(), ansSet.end());
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        vector<string> ans = ob.all_longest_common_subsequences(s, t);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends