//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int countPartitions(vector<int>& arr, int d) {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if((sum + d) % 2 != 0) return 0;
        
        int target = (sum + d) / 2;
        
        vector<int> dp(target + 1, 0);
        dp[0] = 1; 
        for(int num : arr) {
            for(int j = target; j >= num; --j) {
                dp[j] += dp[j - num]; 
            }
        }
        
        return dp[target];
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.countPartitions(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends