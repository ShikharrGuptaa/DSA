class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        // Map of Ball associated w color to Nums of balls
        unordered_map<int, int> color_nos;
        // Map of Ball associated w Ball to Colors
        unordered_map<int, int> ball_color;
        vector<int> ans;

        for(int i = 0; i < queries.size(); ++i){
            int ball = queries[i][0];
            int color = queries[i][1];

            // If Ball Exists already, so we'll have to check for prior colors
            if(ball_color.find(ball) != ball_color.end()){
                int colorToRemove = ball_color[ball];
                color_nos[colorToRemove]--;
                if(color_nos[colorToRemove] == 0) color_nos.erase(colorToRemove);
                
            }
            // Updating the new ball and color;
            ball_color[ball] = color;
            color_nos[color]++;

            ans.push_back(color_nos.size());
        }

        return ans;
    }
};