class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n, 0);
        int k = 0;

        for(int i = 0; i < n-1; ++i){
            if(nums[i] != 0){
                if(nums[i] == nums[i+1]){
                    ans[k] = nums[i]*2;
                    nums[i+1] = 0;
                    ++i;
                }
                else{
                    ans[k] = nums[i];
                }
                k++;
            }
        }

        if(nums[n-1] != 0){
            ans[k++] = nums[n-1];
        }
        return ans;
    }
};