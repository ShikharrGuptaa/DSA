//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isBipartite(vector<vector<int>>& adj) {
        // Code here
        int V = adj.size();
        // Intially all nodes are colourless i.e -1
        vector<int> color(V, -1);
        
        queue<int> q;
        q.push(0);
        color[0] = 0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto adjNode: adj[node]){
                // If adjNode is not colored yet
                if(color[adjNode] == -1){
                    // Color it oppositly
                    color[adjNode] = !color[node];
                    q.push(adjNode);
                }
                // If AdjNode and current Node have same color, meaning it's not a bipartite
                else if(color[adjNode] == color[node]) return false;
            }
        }
        
        return true;
        
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
        bool ans = obj.isBipartite(adj);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends