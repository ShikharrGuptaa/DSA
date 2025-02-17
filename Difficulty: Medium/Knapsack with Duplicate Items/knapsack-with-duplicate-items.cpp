//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
private:
    int help(int idx, int capacity, vector<int>& val, vector<int>& wt, vector<vector<int>> &dp){
        if(capacity == 0) return 0;
        if(idx < 0) return 0;
        
        if(dp[idx][capacity] != -1) return dp[idx][capacity];
        
        int exclude = help(idx-1, capacity, val, wt, dp);
        int include = 0;
        if(wt[idx] <= capacity){
            include = val[idx] + help(idx, capacity - wt[idx], val, wt, dp);
        }
        
        return dp[idx][capacity] = max(include, exclude);
    }
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        vector<vector<int>> dp(wt.size(), vector<int>(capacity+1, -1));
        return help(wt.size()-1, capacity, val, wt, dp);
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int W;
        cin >> W;
        cin.ignore();
        string str;
        getline(cin, str);
        stringstream ss(str);
        vector<int> val;
        int num;
        while (ss >> num) {
            val.push_back(num);
        }
        string str2;
        getline(cin, str2);
        stringstream ss2(str2);
        vector<int> wt;
        int num2;
        while (ss2 >> num2) {
            wt.push_back(num2);
        }
        Solution ob;
        cout << ob.knapSack(val, wt, W) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends