//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
private:
    bool isValid(int m, int maxPages, const vector<int> &arr){
        int stu = 1, pagesSum = 0;
        
        for(int pages: arr){
            if(pagesSum + pages > maxPages){
                stu++;
                pagesSum = pages;
                if(stu > m) return false;
            }
            else{
                pagesSum += pages;
            }
        }
        
        return true;
    }
  public:
    int findPages(vector<int> &arr, int k) {
        // code here
        if(k > arr.size()) return -1;
        int lowLim = *max_element(arr.begin(), arr.end());
        int highLim = accumulate(arr.begin(), arr.end(), 0);
        if(k == arr.size()) return lowLim;
        if(k == 1) return highLim;
        
        int result = highLim;
        
        while(lowLim <= highLim){
            int mid = lowLim + (highLim - lowLim) / 2;
            
            if(isValid(k, mid, arr)){
                result = mid;
                highLim = mid-1;
            }
            else{
                lowLim = mid+1;
            }
        }
        
        return result;

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
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends