class Solution {
private:
    void dfs(int i, int j, vector<vector<char>>& grid){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0') return;

        grid[i][j] = '0';
        
        // Going in all Four Directions
        dfs(i-1, j, grid);
        dfs(i, j+1, grid);
        dfs(i+1, j, grid);
        dfs(i, j-1, grid);
    }

    void bfs(int i, int j, vector<vector<char>> &grid){
        // We need to save islands, and the only way to get islands is via co-ordinates
        queue<pair<int, int>> q;
        q.push({i, j});

        // Marking it Visited
        grid[i][j] = '0';

        int dir[] = {-1, 0, 1, 0, -1};


        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();

            // Going in all four Directions
            for(int i = 0; i < 4; ++i){
                int nx = x + dir[i];
                int ny = y + dir[i+1];

                if(nx >= 0 && ny >= 0 && nx < grid.size() && ny < grid[0].size() && grid[nx][ny] == '1'){
                    grid[nx][ny] = '0';
                    q.push({nx, ny});
                }
            }

        }

    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == '1'){
                    // bfs(i, j, grid);
                    dfs(i, j, grid);
                    cnt++;
                }
            }
        }
    return cnt;
    }

};