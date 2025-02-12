class Solution {
private: 
    void bfs(int src, vector<vector<int>> &adjList, vector<int> &vis){
        queue<int> q;// Queue to process the elemnet;
        q.push(src);
        vis[src] = 1;

        while(!q.empty()){
            int Node = q.front();
            q.pop();

            for(auto adjNode: adjList[Node]){
                if(!vis[adjNode]){
                    vis[adjNode] = 1;
                    q.push(adjNode);
                }
            }
        }
    }

    void dfs(int src, vector<vector<int>> &adjList, vector<int> &vis){
        vis[src] = 1;

        for(auto adjNode: adjList[src]){
            if(!vis[adjNode]){
                dfs(adjNode, adjList, vis);
            }
        }
    }

    void dfsMatrix(int src, vector<vector<int>>& isConnected, vector<int> &vis){
        vis[src] = 1;

        for(int adjNode = 0; adjNode < isConnected.size(); ++adjNode){
            if(isConnected[src][adjNode] == 1 && !vis[adjNode]){
                dfsMatrix(adjNode, isConnected, vis);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        // Vertices
        int V = isConnected.size();
        vector<vector<int>> adjList(V);
        vector<int> vis(V, 0);

        for(int i = 0; i < V; ++i){
            for(int j = 0; j < V; ++j){
                if(isConnected[i][j] == 1 && i != j){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        int cnt = 0;
        for(int i = 0; i < V; ++i){
            if(!vis[i]){
                // bfs(i, adjList, vis);
                // dfs(i, adjList, vis);
                dfsMatrix(i, isConnected, vis);
                cnt++;
            }
        }

        return cnt;
    }
};