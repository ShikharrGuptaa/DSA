class Solution {
private:
    void dfs(int src, vector<vector<int>>& isConnected,  vector<int> &vis){
        vis[src] = 1;

        for(int adjNode = 0; adjNode < isConnected.size(); ++adjNode){
            if(isConnected[src][adjNode] == 1 && !vis[adjNode]){
                dfs(adjNode, isConnected, vis);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int count = 0;

        vector<int> vis(n, 0);

        for(int i = 0; i < n; ++i){
            if(!vis[i]){
                dfs(i, isConnected, vis);
                count++;
            }
        }

        return count;
    }
};