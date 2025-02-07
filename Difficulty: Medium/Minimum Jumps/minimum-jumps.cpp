//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution {
  public:
    int minJumps(vector<int>& nums) {
        // code here
        if(nums.size() == 1) return 0;
        if(nums[0] == 0) return -1;
        int jumps = 0;
        int end = 0; // End of a jump
        int farthest = 0; // Longest one can jump
        
        for(int i = 0; i < nums.size() - 1; ++i){
            // Maximum one can jump from that index
            farthest = max(farthest, i + nums[i]);
            
            // If jump reaching end or over it, we'll take the jump and break from here
            if(farthest >= nums.size()-1){
                return jumps+1;
            }
            
            // We'll take the jump right now and our end'll the farthest
            // if we've reached the end of our first jump
            if(i == end){
                if(end == farthest) return -1;
                ++jumps;
                end = farthest;
            }
            
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl << "~\n";
    }
    return 0;
}

// } Driver Code Ends