//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        
        priority_queue<int> pq;
        
        for(int i = 0; i < arr.size(); ++i){
            if(i < k){
                pq.push(arr[i]);
            }
            else{
                if(arr[i] < pq.top()){
                    pq.pop();
                    pq.push(arr[i]);
                }
            }
        }
        
        return pq.top();
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
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
        k = crr[0];
        int n = arr.size();
        Solution ob;
        cout << ob.kthSmallest(arr, k) << endl << "~\n";
    }
    return 0;
}

// } Driver Code Ends