//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
private:
    void help(vector<vector<int>>& adj, unordered_map<int, bool> &visited, vector<int> &ans, int node){
        
        ans.push_back(node);
        visited[node] = 1;
        
        for(auto i : adj[node]){
            if(!visited[i]){
                help(adj, visited, ans, i);
            }
        }
        
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        // Code here
        unordered_map<int, bool> visited;
        vector<int> ans;
        
        for(int i = 0; i < adj.size(); ++i){
            if(!visited[i]){
                help(adj, visited, ans, 0);
                visited[i] = true;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(
            V); // Use vector of vectors instead of array of vectors.

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        Solution obj;
        vector<int> ans = obj.dfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends