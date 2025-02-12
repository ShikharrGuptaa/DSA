class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        queue<pair<int, int>> q;

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(mat[i][j] == 0) q.push({i, j});
                else mat[i][j] = -1; // Marking it unprocessed
            }
        }
        
        int dir[] = {-1, 0, 1, 0, -1};

        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();

            for(int i = 0; i < 4; ++i){
                int nx = x + dir[i];
                int ny = y + dir[i+1];

                // Skip element which is already processed;
                if(nx < 0 || ny < 0 || nx >= m || ny >= n || mat[nx][ny] != -1) continue;
                else{
                    mat[nx][ny] = 1 + mat[x][y];
                    q.push({nx, ny});
                }
            }
        }

        return mat;
    }
};