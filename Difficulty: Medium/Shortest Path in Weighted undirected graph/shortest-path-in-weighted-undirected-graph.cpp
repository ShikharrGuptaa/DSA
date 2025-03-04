//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<vector<pair<int, int>>> adj(n+1);
        for(auto &it: edges){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n+1, INT_MAX), parent(n+1);
        vector<int>  vis(n+1, 0);
        
        for(int i = 1; i <= n; ++i) parent[i] = i;
        
        
        dist[1] = 0;
        pq.push({0, 1});
        
        while(!pq.empty()){
            int currDist = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();
            
            if(vis[currNode]) continue;
            vis[currNode] = 1;
            
            for(auto &neighbor : adj[currNode]){
                int adjNode = neighbor.first;
                int weight = neighbor.second;
                
                if(weight + currDist < dist[adjNode]){
                    dist[adjNode] = weight + currDist;
                    pq.push({dist[adjNode], adjNode});
                    parent[adjNode] = currNode;
                }
            }
        }
        
        if(dist[n] == INT_MAX) return {-1};
        
        vector<int> path;
        int node = n;
        while(parent[node] != node){
            path.push_back(node);
            node = parent[node];
        }
        
        path.push_back(1);
        path.push_back(dist[n]);
        reverse(path.begin(), path.end());
        return path;
        
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
            mp[{edges.back()[0], edges.back()[1]}] = edges.back()[2];
            mp[{edges.back()[1], edges.back()[0]}] = edges.back()[2];
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        int ans = 0;
        for (int i = 2; i < res.size(); i++) {
            ans += mp[{res[i], res[i - 1]}];
        }
        if (ans == res[0]) {

        } else if (res.size() == 1 && res[0] == -1)
            ans = res[0];
        else
            ans = -2;
        cout << ans << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends