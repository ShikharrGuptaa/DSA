class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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

        return topo.size() == numCourses ? true : false;
    }
};