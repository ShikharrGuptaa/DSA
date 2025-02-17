//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        vector<int> dp(n, -1);
        return help(n-1, height, dp);
    }
    
    int help(int idx, vector<int> &height, vector<int> &dp){
        if(idx == 0) return 0;
        if(idx == 1) return dp[idx] = abs(height[idx] - height[idx-1]);
        
        if(dp[idx] != -1) return dp[idx];
        
        int opt1 = abs(height[idx] - height[idx-1]) + help(idx-1, height, dp);
        int opt2 = abs(height[idx] - height[idx-2]) + help(idx-2, height, dp);
        
        return dp[idx] = min(opt1, opt2);
    }
};

//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends