//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isPossible(int numCourses, int P, vector<pair<int, int> >& prerequisites) {
        // Code here
        vector<vector<int>> adjList(numCourses);
        vector<int> inDegree(numCourses, 0);
        vector<int> topo;
        queue <int> q;
        
        for(auto vec : prerequisites){
            adjList[vec.second].push_back(vec.first);
            inDegree[vec.first]++;
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

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends