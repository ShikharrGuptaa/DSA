class Solution {
private:
    vector<pair<int, int>> emptyCells, extraOnes;
    int help(int idx, vector<vector<int>>& grid){
        if(idx == emptyCells.size()) return 0;

        auto& [x, y] = emptyCells[idx];
        int minMoves = INT_MAX;

        // Backtrack

        for(auto& [nx, ny] : extraOnes){
            if(grid[nx][ny] > 1){
                grid[nx][ny]--;
                grid[x][y]++;
                
                int dist = abs(x - nx) + abs(y - ny);
                minMoves = min(minMoves, dist + help(idx+1, grid));

                grid[x][y]--;
                grid[nx][ny]++;
            }
        }
        return minMoves;
    }
public:
    int minimumMoves(vector<vector<int>>& grid) {
        emptyCells.clear();
        extraOnes.clear();

        for(int i = 0; i < 3; ++i){
            for(int j = 0; j < 3; ++j){
                if (grid[i][j] == 0) emptyCells.push_back({i, j});
                if (grid[i][j] > 1) extraOnes.push_back({i, j});
            }
        }

        return help(0, grid);
    }
};