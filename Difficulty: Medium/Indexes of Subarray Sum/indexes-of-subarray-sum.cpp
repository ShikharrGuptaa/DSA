//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        unordered_map<int, int> mp;
        
        int sum = 0;
        
        for(int i = 0; i < arr.size(); ++i) {
            sum += arr[i];
            // If subarray starts from index 1
            if (sum == target) {
                return {1, i + 1}; // 1-based indexing
            }
            // Check if `sum - target` exists in the map
            if (mp.find(sum - target) != mp.end()) {
                return {mp[sum - target] + 1, i + 1}; // Convert 0-based to 1-based
            }
            // Store the sum at index (1-based index handling)
            mp[sum] = i + 1;
        }

        return {-1};
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int d;
        string input;

        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        cin >> d;
        cin.ignore();

        Solution ob;
        vector<int> result = ob.subarraySum(arr, d);
        for (int i : result) {
            cout << i << " ";
        }
        cout << "\n~\n";
    }
    return 0;
}

// } Driver Code Ends