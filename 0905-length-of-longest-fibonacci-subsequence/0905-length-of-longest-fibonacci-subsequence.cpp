class Solution {
private:
    unordered_map<int, int> mapping;
    unordered_map<int, unordered_map<int, int>> dp;
    
    int help(int first, int second, vector<int> &arr){
        int next = first + second;
        if(mapping.find(next) == mapping.end()) return 2;

        int next_idx = mapping[next];

        if(dp[first][second]) return dp[first][second];

        return dp[first][second] = 1 + help(second, arr[next_idx], arr);
    }
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();

        for(int i = 0; i < n; ++i){
            mapping[arr[i]] = i;
        }
        int maxAns = 0;

        for(int i = 0; i < n; ++i){
            for(int j = i + 1; j < n; ++j){
                maxAns = max(maxAns, help(arr[i], arr[j], arr));
            }
        }

        return maxAns > 2 ? maxAns : 0;
    }
};