//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
private:
    bool dfs(int src, vector<int> &vis, vector<int> &pathVis, vector<vector<int>> &adj){
        // Marked it as Visited
        vis[src] = 1;
        // Marked the path Visited too
        pathVis[src] = 1;
        
        for(auto adjNode : adj[src]){
            if(!vis[adjNode]){
                if(dfs(adjNode, vis, pathVis, adj)) return true;
            }
            else if(pathVis[adjNode]) return true;
        }
        pathVis[src] = 0;
        return false;
        
    }
public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<vector<int>> adj) {
        // code here
        vector<int> inDeg(V, 0);
        for(int i = 0; i < V; ++i){
            for(auto adjNode: adj[i]){
                inDeg[adjNode]++;
            }
        }
        
        queue<int> q;
        
        for(int i = 0; i < V; ++i){
            if(inDeg[i] == 0) q.push(i);
        }
        
        vector<int> topo;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            
            for(auto adjNode: adj[node]){
                inDeg[adjNode]--;
                if(inDeg[adjNode] == 0) q.push(adjNode);
            }
        }
        
        return topo.size() == V ? false : true;
        
        
        
        
        
        // ---------------DFS SOLUTION--------------
        // vector<int> vis(V, 0);
        // vector<int> pathVis(V, 0);
        
        // for(int i = 0; i < V; ++i){
        //     if(!vis[i]){
        //         if(dfs(i, vis, pathVis, adj)) return true;
        //     }
        // }
        
        // return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends