//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string longestCommonPrefix(vector<string> arr) {
        // your code here
        sort(arr.begin(), arr.end());
        int n = arr.size();
        string str1 = arr[0], str2 = arr[n-1];
        
        int ptr1 = 0, ptr2 = 0;
        
        string ans = "";
        while(ptr1 < str1.size() && ptr2 < str2.size() && str1[ptr1] == str2[ptr2]){
            ans += str1[ptr1];
            ptr1++;
            ptr2++;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        string ans = ob.longestCommonPrefix(arr);
        if (ans.empty())
            cout << "\"\"";
        else
            cout << ans;
        cout << endl;
    }
}

// } Driver Code Ends