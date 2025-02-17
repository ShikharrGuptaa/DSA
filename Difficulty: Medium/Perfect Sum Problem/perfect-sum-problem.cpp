//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
public:
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return help(n - 1, target, arr, dp);
    }

    int help(int idx, int target, vector<int>& arr, vector<vector<int>>& dp) {
        if (idx < 0) {
            return (target == 0) ? 1 : 0;
        }
        if (dp[idx][target] != -1) return dp[idx][target];

        int exclude = help(idx - 1, target, arr, dp);
        int include = 0;
        if (arr[idx] <= target) {
            include = help(idx - 1, target - arr[idx], arr, dp);
        }

        return dp[idx][target] = include + exclude;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int target;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> target;
        cin.ignore(); // Ignore newline character after target input

        Solution solution;
        cout << solution.perfectSum(arr, target);
        cout << "\n~\n";
    }

    return 0;
}

// } Driver Code Ends