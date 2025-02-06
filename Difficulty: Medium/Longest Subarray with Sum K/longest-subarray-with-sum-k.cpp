//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        // map<difference, index> 
        int n = arr.size();
        unordered_map<int, int> mp;
        int pre = 0;
        int longest = 0;
        
        for(int i = 0; i < n; ++i){
            pre += arr[i]; // Curr is processed
            
            if (pre == k) { 
                longest = max(longest, i + 1);
            }
            
            int diff = pre - k;
            if (mp.find(diff) != mp.end()) {
                longest = max(longest, i - mp[diff]);
            }
            
            if (mp.find(pre) == mp.end()) { 
                mp[pre] = i;
            }
        }
        
        return longest;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution solution;
        cout << solution.longestSubarray(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends