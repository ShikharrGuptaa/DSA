//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    vector<int> findOrder(int numCourses, int m, vector<vector<int>> prerequisites) 
    {
        //code here
        vector<vector<int>> adjList(numCourses);
        vector<int> inDegree(numCourses, 0);
        vector<int> topo;
        queue <int> q;
        
        for(auto vec : prerequisites){
            adjList[vec[1]].push_back(vec[0]);
            inDegree[vec[0]]++;
        }
        // Processing all the nodes with inDegree 0;
        
        for(int i = 0; i < numCourses; ++i){
            if(inDegree[i] == 0) q.push(i);
        }

        // Processing the queue
        while(!q.empty()){
            int node = q.front();
            q.pop();

            topo.push_back(node);
            for(auto adjNode: adjList[node]){
                inDegree[adjNode]--;
                if(!inDegree[adjNode]) q.push(adjNode);
            }
        }

        if(topo.size() == numCourses) return topo;
        return {};
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    
cout << "~" << "\n";
}
    
    return 0;
}
// } Driver Code Ends