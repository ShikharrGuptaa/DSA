class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1), hash(n, 0);
        int maxi = 1, lastindex = 0;

        for(int i = 1; i < n; ++i){
            hash[i] = i;
            for(int prev = 0; prev < i; ++prev){
                if(!(nums[i] % nums[prev]) && dp[i] < 1 + dp[prev]){
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }

            if(dp[i] > maxi){
                maxi = dp[i];
                lastindex = i;
            }
        }

        vector<int> ans;
        ans.push_back(nums[lastindex]);
        while(hash[lastindex] != lastindex){
            lastindex = hash[lastindex];
            ans.push_back(nums[lastindex]);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};