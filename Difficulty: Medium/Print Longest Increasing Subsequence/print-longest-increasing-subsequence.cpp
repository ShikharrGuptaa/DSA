//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        vector<int> backtrack(n, 0), LIS(n, 1);
        int lastIdx = 0, maxi = 1;
        
        for(int idx = 0; idx < n; ++idx){
            backtrack[idx] = idx;
            
            for(int prev = 0; prev < idx; ++prev){
                if(arr[prev] < arr[idx] && 1 + LIS[prev] > LIS[idx]){
                    LIS[idx] = 1 + LIS[prev];
                    backtrack[idx] = prev;
                }
            }
            
            if(LIS[idx] > maxi){
                maxi = LIS[idx];
                lastIdx = idx;
            }
        }
        
        // Reconstruct LIS
        vector<int> ans;
        ans.push_back(arr[lastIdx]);
        while(backtrack[lastIdx] != lastIdx){
            lastIdx = backtrack[lastIdx];
            ans.push_back(arr[lastIdx]);
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res)
            cout << x << " ";
        cout << "\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends