//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
private:
    void dfs(int i, int j, int baseX, int baseY, vector<vector<int>>& grid, string &temp){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0) return;
        
        grid[i][j] = 0;
        temp += (to_string(i - baseX) + to_string(j - baseY));
        
        dfs(i-1, j, baseX, baseY, grid, temp);
        dfs(i, j-1, baseX, baseY, grid, temp);
        dfs(i+1, j, baseX, baseY, grid, temp);
        dfs(i, j+1, baseX, baseY, grid, temp);
    }
public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int m = grid.size(), n = grid[0].size();
        
        set<string> st;
        
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 1){
                    string temp = "";
                    dfs(i, j, i, j, grid, temp);
                    st.insert(temp);
                }
            }
        }
        
        
        return st.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends