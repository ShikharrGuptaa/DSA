//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Position this line where user code will be pasted.
class Solution {
private:
    void dfs(int src, vector<int> &vis, stack<int> &st, vector<vector<int>> &adj){
        vis[src] = 1;
        
        for(auto adjNode: adj[src]){
            if(!vis[adjNode]){
                dfs(adjNode, vis, st, adj);
            }
        }
        st.push(src);
    }
    void dfs(int src, vector<int> &vis, vector<vector<int>> &adj){
        vis[src] = 1;
        
        for(auto adjNode: adj[src]){
            if(!vis[adjNode]){
                dfs(adjNode, vis, adj);
            }
        }
    }

  public:
    int kosaraju(vector<vector<int>> &adj) {
        // code here
        int V = adj.size();
        vector<int> vis(V, 0);
        stack<int> st;
        
        for(int i = 0; i < V; ++i){
            if(!vis[i]){
                dfs(i, vis, st, adj);
            }
        }
        
        vector<vector<int>> revAdj(V);
        for(int u = 0; u < V; ++u){
            vis[u] = 0;
            for(auto v : adj[u]){
                revAdj[v].push_back(u);
            }
        }
        
        
        int scc = 0;
        while(!st.empty()){
            int src = st.top();
            st.pop();
            if(!vis[src]){
                scc++;
                dfs(src, vis, revAdj);
            }
        }
        
        return scc;
        
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
        cout << obj.kosaraju(adj) << "\n";

        // cout << "~"
        //      << "\n";
    }

    return 0;
}

// } Driver Code Ends