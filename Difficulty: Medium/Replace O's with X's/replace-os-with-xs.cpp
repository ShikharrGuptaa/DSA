//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
private:
    int DIR[5] = {-1, 0, 1, 0, -1}; 
    void bfs(int i, int j, vector<vector<char>>& board, vector<vector<int>> &vis){
        queue<pair<int, int>> q;
        q.push({i, j});
        vis[i][j] = 1;

        while(!q.empty()){
            auto x = q.front().first;
            auto y = q.front().second;
            q.pop();

            for(int i = 0; i < 4; ++i){
                int nx = x + DIR[i];
                int ny = y + DIR[i+1];
                if(nx >= 0 && ny >= 0 && nx < board.size() && ny < board[0].size() && board[nx][ny] == 'O' && !vis[nx][ny]){
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
    }

    void dfs(int i, int j, vector<vector<char>>& board, vector<vector<int>> &vis){
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == 'X' || vis[i][j] == 1) return;

        vis[i][j] = 1;

        dfs(i-1, j, board, vis);
        dfs(i, j-1, board, vis);
        dfs(i+1, j, board, vis);
        dfs(i, j+1, board, vis);
    }
    
  public:
    vector<vector<char>> fill(vector<vector<char>>& board) {
        // code here
        int m = board.size(), n = board[0].size();

        // Created a Visited Board;
        vector<vector<int>> vis(m, vector<int>(n, 0));

        for(int i = 0; i < m; ++i){
            if(board[i][0] == 'O' && !vis[i][0]){
                bfs(i, 0, board, vis);
            }

            if(board[i][n-1] == 'O' && !vis[i][n-1]){
                bfs(i, n-1, board, vis);
            }
        }

        for(int j = 0; j < n; ++j){
            if(board[0][j] == 'O' && !vis[0][j]){
                bfs(0, j, board, vis);
            }

            if(board[m-1][j] == 'O' && !vis[m-1][j]){
                bfs(m-1, j, board, vis);
            }
        }

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(vis[i][j] == 0 && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
        
        return board;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];

        Solution ob;
        vector<vector<char>> ans = ob.fill(mat);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends