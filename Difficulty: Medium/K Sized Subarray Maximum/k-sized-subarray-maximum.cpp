//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find maximum of each subarray of size k.
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        priority_queue<pair<int, int>> pq;
        vector<int> ans;
        
        int n = arr.size();
        
        // 1st window Processed
        for(int idx = 0; idx < k; idx++){
            pq.push({arr[idx], idx});
        }
        
        // Fist window answer processed
        ans.push_back(pq.top().first);
        
        for(int idx = k; idx < n; ++idx){
            pq.push({arr[idx], idx});
            while(pq.top().second <= idx - k) pq.pop();
            
            ans.push_back(pq.top().first);
        }
        
        return ans;
        
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

        Solution obj;
        vector<int> res = obj.maxOfSubarrays(arr, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends