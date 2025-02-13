class Solution {
private:
    void help(vector<int> &path, vector<int> &vis, vector<int>& nums, vector<vector<int>> &result){
        if(path.size() == nums.size()){
            result.push_back(path);
            return;
        }

        for(int idx = 0; idx < nums.size(); ++idx){
            // What're we Checking here
            // First thing like permutation 1 
            // 1) Num shouldn't be already visited AND
            // 2) Number Should't be skipped earlier and the same number is taken again
            // TO check 2nd condn, we wrote
            // If idx is at 0, so it's ok, we can't check prev element
            // Or if idx is not 0 but prev element is not equal to current elem then also it's okay
            // Or if previous element is same as curr but make sure we didn't skipped it last time otherwise it won't be--
            // --any use to skip and take the same element in this iteration for same pos
            // Basically if skipped one number for a position, skipp all duplicates of that num for that pos
            // All this while keeping in mind that number isn't visited
            if(!vis[idx] && (idx == 0 || nums[idx] != nums[idx-1] || vis[idx-1])){
                path.push_back(nums[idx]);
                vis[idx] = 1;
                help(path, vis, nums, result);
                vis[idx] = 0;
                path.pop_back();
            }
        }

    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        // To store the permutation
        vector<int>path;
        vector<int> vis(nums.size(), 0);
        sort(nums.begin(), nums.end());
        help(path, vis, nums, result);
        return result;
    }
};