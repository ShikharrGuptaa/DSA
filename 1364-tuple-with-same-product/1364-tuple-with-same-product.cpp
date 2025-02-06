class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = 0, n = nums.size();
        for(int i = 0; i < n; i++){
            for(int j = 1+i; j < n; ++j){
                int prod = nums[i] * nums[j];

                ans+= 8 * mp[prod];
                mp[prod]++;
            }
        }

        return ans;
    }
};