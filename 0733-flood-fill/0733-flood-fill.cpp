class Solution {
private:
    void dfs(int i, int j, int color, int colorToFill, vector<vector<int>>& image){
        if(i < 0 || j < 0 || i >= image.size() || j >= image[0].size() || image[i][j] != colorToFill) return;

        image[i][j] = color;

        dfs(i-1, j, color, colorToFill, image);
        dfs(i, j+1, color, colorToFill, image);
        dfs(i+1, j, color, colorToFill, image);
        dfs(i, j-1, color, colorToFill, image);
    }

    void bfs(int i, int j, int color, int colorToFill, vector<vector<int>> &image){
        queue<pair<int, int>> q;
        q.push({i, j});
        // Marking Visited
        image[i][j] = color;

        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();

            int dir[] = {-1, 0, 1, 0, -1};

            for(int i = 0; i < 4; ++i){
                int nx = x + dir[i];
                int ny = y + dir[i+1];

                if(nx >= 0 && ny >= 0 && nx < image.size() && ny < image[0].size() && image[nx][ny] == colorToFill){
                    image[nx][ny] = color;
                    q.push({nx, ny});
                }
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int colorToFill = image[sr][sc];
        if (color == colorToFill) return image;

        // dfs(sr, sc, color, colorToFill, image);
        bfs(sr, sc, color, colorToFill, image);

        return image;
    }
};