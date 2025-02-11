//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
private: 
    bool detect(int src, vector<vector<int>>& adj, unordered_map<int, bool> &visited) {
        queue<pair<int, int>> q; // Node Parent
        q.push({src, -1});
        visited[src] = true; 

        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (auto adjacentNode : adj[node]) {
                if (!visited[adjacentNode]) {
                    visited[adjacentNode] = true;
                    q.push({adjacentNode, node});
                }
                else if (adjacentNode != parent) {
                    return true; 
                }
            }
        }
        return false; 
    }

public:
    bool isCycle(vector<vector<int>>& adj) {
        unordered_map<int, bool> visited;
        
        for (int idx = 0; idx < adj.size(); idx++) {
            if (!visited[idx]) {
                if (detect(idx, adj, visited)) return true;
            }
        }
        return false;
    }
};




//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends