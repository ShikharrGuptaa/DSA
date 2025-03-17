//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        return help(arr, target, n, dp);
    }
    
    bool help(vector<int> &arr, int target, int n, vector<vector<int>> &dp){
        if(target == 0) return true;
        if(n == 0) return false;
        
        if(dp[n][target] != -1) return dp[n][target];
        // Checking first
        if(arr[n-1] > target){
            // DOn't Include
            return dp[n][target] = help(arr, target, n-1, dp);
        }
        // Either include or don't;
        return dp[n][target] = help(arr, target - arr[n-1], n-1, dp) || help(arr, target, n-1, dp);
    }
};




//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends