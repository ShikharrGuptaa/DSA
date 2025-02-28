//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> findTwoElement(vector<int>& nums) {
        // code here
        int n = nums.size();
        int sumOfN = 0;
        int sumOfNSq = 0;

    // Sum of n natural numbers and n*n natural numbers
        for(int i = 1; i <= n; ++i){
            sumOfN += i;
            sumOfNSq += (i*i);
        }

        int originalSum = 0;
        int originalSumSq = 0;

        for(int i : nums){
            originalSum += i;;
            originalSumSq += (i*i);
        }
    //  Missing - Repeat
        int miss_rep_normal = sumOfN - originalSum;
        int miss_rep_sq = sumOfNSq - originalSumSq;
        int miss_rep_sum = miss_rep_sq/miss_rep_normal;
        int misssing  = (miss_rep_sum + miss_rep_normal)/2;

        int repeating = miss_rep_sum - misssing;

        return {repeating, misssing};
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;
        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        auto ans = ob.findTwoElement(arr);
        cout << ans[0] << " " << ans[1] << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends