//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find minimum time required to rot all oranges.
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int m = grid.size(), n = grid[0].size();
        // To keep track of Rotten Oranges
        queue<pair<int, int>> q;
        int freshCount = 0, minutes = 0;

        // Step 1 : Pushing all rotten ones in queue, and keeping track of all fresh ones
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
                else if(grid[i][j] == 1){
                    freshCount++;
                }
            }
        }

        int dir[] = {-1, 0, 1, 0, -1};

        // Step 2 : Multi Souce BFS
        while(!q.empty() && freshCount > 0){
            // We'll only process each level at one time and increase minutes when level increase or we won't
            int size = q.size();
            minutes++;
            
            // Processing all nodes upto size, as they are in the level right now
            for(int i = 0; i < size; ++i){
                
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for(int d = 0; d < 4; ++d){
                    int nx = x + dir[d];
                    int ny = y + dir[d+1];
                    
                    // Only process if it's a freshOrange
                    if(nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == 1){
                        // Rot current Orange
                        grid[nx][ny] = 2;
                        // Decrease freshCount;
                        freshCount--;
                        // Process the next rotten orange for next level
                        q.push({nx, ny});
                    } 
                }
            }
        }

        return freshCount > 0 ? -1 : minutes;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(mat);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends