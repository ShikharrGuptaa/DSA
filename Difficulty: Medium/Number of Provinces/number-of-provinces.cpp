//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
private: 
    void dfs(int src, vector<vector<int>> &adj, vector<int> &vis){
        vis[src] = 1;
        
        for(int adjCity = 0; adjCity < adj.size(); ++adjCity){
            if(adj[src][adjCity] == 1 && !vis[adjCity]){
                dfs(adjCity, adj, vis);
            }
        }
    }
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int> vis(V, 0);
        int count = 0;
        
        for(int i = 0; i < V; ++i){
            if(!vis[i]){
                dfs(i, adj, vis);
                count++;
            }
        }
        
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends